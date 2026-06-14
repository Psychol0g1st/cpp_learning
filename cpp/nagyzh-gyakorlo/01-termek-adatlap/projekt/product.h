#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
    string id;
    string name;
    int price;
public:
    Product(const string& id, const string& name, int price);

    const string& getId() const;
    const string& getName() const;
    int getPrice() const;

    void print() const;
};

#endif
