#include "product.h"
#include <iostream>
using namespace std;

Product::Product(const string& id, const string& name, int price)
    : id(id), name(name), price(price) {}

const string& Product::getId() const {
    return id;
}

const string& Product::getName() const {
    return name;
}

int Product::getPrice() const {
    return price;
}

void Product::print() const {
    cout << "#" << id << ": " << name << ", " << price << " Ft" << endl;
}
