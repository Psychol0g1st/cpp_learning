#include "wallet.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

#include "csingle.h"
#include "cmulti.h"
#include "cmonthly.h"

Wallet::Wallet() {}

Wallet::~Wallet()
{
    for (size_t i=0;i<coupons.size();i++)
        delete coupons[i];
}

void Wallet::addCoupon(Coupon *newCoupon)
{
    coupons.push_back(newCoupon);
}

int Wallet::useAllAndGetTotalDiscount()
{
    int totalDiscount=0;
    for (size_t i=0;i<coupons.size();i++)
    {
        if (coupons[i]->isValid())
        {
            coupons[i]->use();
            totalDiscount += coupons[i]->getValue();
        }
    }
    return totalDiscount;
}

void Wallet::loadCoupons(const string &filePath)
{
    ifstream in(filePath);
    if (!in.is_open())
        throw runtime_error("Nem sikerult megnyitni: "
                            + filePath);

    json root = json::parse(in);
    for (size_t i=0;i<root.size();i++)
    {
        json& current = root[i];
        string type = current["Type"];
        int value = current["Value"]; // mindharomban van
        Coupon* c=nullptr; // az uj kupon
        if (type == "Single use")
        {
            c = new CSingle(value);
        }
        else if (type == "Multiple use")
        {
            int totalUses = current["TotalUses"];
            c = new CMulti(value,totalUses);
        }
        else if (type == "Monthly")
        {
            int year = current["Year"];
            int month = current["Month"];
            c = new CMonthly(value,year,month);
        }
        else throw runtime_error("Ismeretlen kupon tipus: "
                                + type); // nem fordulhat elo
        coupons.push_back(c);
    }
}

void Wallet::exportCounts(const string& filePath) const
{
    int count_1_valid = countCoupons<CSingle>(true);
    int count_1_all = countCoupons<CSingle>();
    int count_2_valid = countCoupons<CMulti>(true);
    int count_2_all = countCoupons<CMulti>();
    int count_3_valid = countCoupons<CMonthly>(true);
    int count_3_all = countCoupons<CMonthly>();

    json root;
    root["Single use"]["Valid"] = count_1_valid;
    root["Single use"]["Invalid"] = count_1_all - count_1_valid;
    root["Multiple use"]["Valid"] = count_2_valid;
    root["Multiple use"]["Invalid"] = count_2_all - count_2_valid;
    root["Monthly"]["Valid"] = count_3_valid;
    root["Monthly"]["Invalid"] = count_3_all - count_3_valid;

    ofstream out(filePath);
    if (!out.is_open())
        throw runtime_error("Nem sikerult megnyitni: "
                            + filePath);
    out << root.dump(4) << endl;
}
