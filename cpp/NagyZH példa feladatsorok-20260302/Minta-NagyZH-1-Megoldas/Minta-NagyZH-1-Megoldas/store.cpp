#include "store.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

#include "fchair.h"
#include "ftable.h"
#include "fwardrobe.h"

int Store::administrationFee = 1000;

Store::~Store()
{
    for (size_t i=0;i<products.size();i++)
        delete products[i];
}

void Store::loadStock(const string &filePath)
{
    ifstream in(filePath);
    if (!in.is_open())
    {
        throw runtime_error("Nem sikerult megnyitni: " + filePath);
    }

    json root = json::parse(in);
    products.clear(); // nem kotelezo
    json& product_array = root["Products"];
    for (size_t i=0;i<product_array.size();i++)
    {
        json& p = product_array[i];
        string type = p["Type"];
        string id = p["Id"];
        string woodType = p["WoodType"];
        double weight = p["Weight"];
        int width = p["Dimensions"]["Width"];
        int height = p["Dimensions"]["Height"];
        int length = p["Dimensions"]["Length"];
        int price = p["Price"];
        if (type == "Chair")
        {
            products.push_back(new FChair(
                id,woodType,weight,width,height,length,price,
                p["Style"]));
        }
        else if (type == "Table")
        {
            products.push_back(new FTable(
                id,woodType,weight,width,height,length,price,
                p["LegCount"],p["LegsAdjustable"]));
        }
        else if (type == "Wardrobe")
        {
            products.push_back(new FWardrobe(
                id,woodType,weight,width,height,length,price,
                p["DoorCount"],p["HasMirror"]));
        }
    }
    quantities.clear(); // nem kotelezo
    quantities.resize(products.size());
    json& stock_array = root["Stock"];
    for (size_t i=0;i<stock_array.size();i++)
    {
        json& s = stock_array[i];
        string id = s["ProductId"];
        int quantity = s["Quantity"];
        // feltehetjuk, hogy az adatok ervenyesek
        quantities[indexOf(id)] = quantity;
    }
}

void Store::printProducts() const
{
    for (size_t i=0;i<products.size();i++)
        products[i]->print();
}

void Store::printStock() const
{
    for (size_t i=0;i<products.size();i++)
    {
        cout << quantities[i] << " X ";
        products[i]->print();
    }
}

Order Store::loadOrder(const string &filePath)
{
    ifstream in(filePath);
    if (!in.is_open())
    {
        throw runtime_error("Nem sikerult megnyitni: " + filePath);
    }

    Order order;

    json root = json::parse(in);
    for (size_t i=0;i<root.size();i++)
    {
        json& item = root[i];
        string id = item["ProductId"];
        int quantity = item["Quantity"];
        order.addProduct(id,quantity);
    }

    return order;
}

int Store::priceOfOrder(const Order &order) const
{
    int sum=0;
    for (size_t k=0;k<order.getSize();k++)
    {
        size_t index = indexOf(order.getId(k));
        sum += products[index]->getPrice() *
               order.getQuantity(k);
    }
    sum += administrationFee;
    return sum;
}

bool Store::deliverOrder(const Order &order)
{
    for (size_t k=0;k<order.getSize();k++)
    {
        size_t index = indexOf(order.getId(k));
        if (quantities[index] < order.getQuantity(k))
            return false;
    }
    for (size_t k=0;k<order.getSize();k++)
    {
        size_t index = indexOf(order.getId(k));
        quantities[index] -= order.getQuantity(k);
    }
    return true;
}

void Store::produce(const string &id, int quantity)
{
    quantities[indexOf(id)] += quantity;
}

void Store::exportQuantities(const string &filePath) const
{
    json root;
    for (size_t i=0;i<products.size();i++)
    {
        root[i]["ProductId"] = products[i]->getId();
        root[i]["Quantity"] = quantities[i];
    }

    ofstream out(filePath);
    out << root.dump(2) << endl;
}

void Store::setAdministrationFee(int administrationFee)
{
    Store::administrationFee = administrationFee;
}

size_t Store::indexOf(const string &productId) const
{
    for (size_t i=0;i<products.size();i++)
        if(products[i]->getId() == productId)
            return i;
    return -1;
}
