#include "purchase.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

Purchase::Purchase(const string &filePath)
{
    ifstream in(filePath);
    if (!in.is_open())
        throw runtime_error("Nem sikerult megnyitni: "
                            + filePath);

    json root = json::parse(in);
    for (size_t i=0;i<root.size();i++)
    {
        json& node = root[i];
        string name = node["Name"];
        int unitPrice = node["UnitPrice"];
        double qValue = node["Quantity"]["Value"];
        string qUnit = node["Quantity"]["Unit"];
        PurchaseItem item(name,unitPrice,qValue,qUnit);
        items.push_back(item);
    }
}

void Purchase::print() const
{
    cout << "Bevasarlas elemei:" << endl;
    for (size_t i=0;i<items.size();i++)
        items[i].print();
}

int Purchase::getTotal() const
{
    int sum=0;
    for (size_t i=0;i<items.size();i++)
        sum += items[i].getTotalPrice();
    return sum;
}

int Purchase::useCoupons(Wallet &wallet) const
{
    int sum = getTotal();
    sum -= wallet.useAllAndGetTotalDiscount();
    return sum;
}
