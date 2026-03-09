#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product
{
    string name;
    double price;
public:
    Product(const string& name,
            double price);

    string getName () const;
    double getPrice () const;

    void print () const;
};

#endif // PRODUCT_H
