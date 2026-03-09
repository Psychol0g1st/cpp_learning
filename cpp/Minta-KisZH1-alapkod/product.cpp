#include "product.h"

#include <iostream>
using namespace std;

Product::Product(const string& name,
                 double price):
    name(name),
    price(price)
{
}

string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}

void Product::print() const
{
    cout << name << " " << price << endl;
}
