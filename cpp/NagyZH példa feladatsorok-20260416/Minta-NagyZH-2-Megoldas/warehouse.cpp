#include "warehouse.h"

#include <fstream>
#include <stdexcept>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

#include "btoy.h"
#include "bclothes.h"
#include "bchair.h"

Warehouse::~Warehouse()
{
    for (size_t i=0;i<products.size();i++)
        delete products[i];
}

void Warehouse::loadProducts(const string &type,
                             const string &filePath)
{
    ifstream in(filePath);
    if (!in.is_open())
        throw runtime_error("Nem sikerult megnyitni: "
                            + filePath);

    json root = json::parse(in);

    for (size_t i=0;i<root.size();i++)
    {
        json& product = root[i];
        string id = product["Id"];
        string name = product["Name"];
        int price = product["Price"];
        int quantity = product["Quantity"];
        BProduct* p = nullptr;
        if (type == "toy")
        {
            int age = product["Age"];
            p = new BToy(id,name,price,quantity,age);
        }
        else if (type == "clothes")
        {
            string size = product["Size"];
            p = new BClothes(id,name,price,quantity,size);
        }
        else if (type == "chair")
        {
            bool canBeSet = product["CanBeSet"];
            p = new BChair(id,name,price,quantity,canBeSet);
        }
        products.push_back(p);
    }
}

const vector<BProduct*> &Warehouse::getProducts() const
{
    return products;
}

vector<BProduct*> Warehouse::getProducts(const string &type) const
{
    vector<BProduct*> result;
    for (size_t i=0;i<products.size();i++)
        if (products[i]->type() == type)
            result.push_back(products[i]);
    return result;
}

void Warehouse::deliverShipment(const Shipment &shipment)
{
    for (size_t i=0;i<shipment.getItemCount();i++)
    {
        string id = shipment.getId(i);
        BProduct* p = get(id);
        if (!p)
            throw runtime_error("Id not found: " + id);
        int quantity = shipment.getQuantity(i);
        p->setQuantity(p->getQuantity() + quantity);
    }
}

bool Warehouse::makeOrder(const string &id,
                          int quantity,
                          int &customerMoney)
{
    BProduct* p = get(id);
    if (!p)
    {
        cout << "Hiba: id nem letezik: " << id << endl;
        return false;
    }
    if (p->getQuantity() < quantity)
    {
        cout << "Hiba: keves van raktaron: "
             << p->getQuantity()
             << " db, ennyi kellene: "
             << quantity << " db" << endl;
        return false;
    }
    int sum = p->getPrice()*quantity;
    if (customerMoney < sum)
    {
        cout << "Hiba: a vasarlo penze keves: "
             << customerMoney
             << " Ft, de ennyi a vegosszeg: "
             << sum << endl;
        return false;
    }
    // minden jo
    customerMoney -= sum;
    p->setQuantity(p->getQuantity() - quantity);
    return true;
}

void Warehouse::saveProducts(const string &type,
                             const string &filePath) const
{
    json root;
    for (size_t i=0;i<products.size();i++)
    {
        if (products[i]->type() == type)
        {
            json product;
            product["Id"] = products[i]->getId();
            product["Name"] = products[i]->getName();
            product["Price"] = products[i]->getPrice();
            product["Quantity"] = products[i]->getQuantity();
            {
                BToy* p = dynamic_cast<BToy*>(products[i]);
                if (p)
                    product["Age"] = p->getAge();
            }
            {
                BClothes* p = dynamic_cast<BClothes*>(products[i]);
                if (p)
                    product["Size"] = p->getSize();
            }
            {
                BChair* p = dynamic_cast<BChair*>(products[i]);
                if (p)
                    product["CanBeSet"] = p->getCanBeSet();
            }
            root.push_back(product);
        }
    }

    ofstream out(filePath);
    if (!out.is_open())
        throw runtime_error("Nem sikerult megnyitni: "
                            + filePath);
    out << root.dump(4) << endl;
}

BProduct *Warehouse::get(const string &id) const
{
    for (size_t i=0;i<products.size();i++)
        if (products[i]->getId() == id)
            return products[i];
    return nullptr;
}
