#ifndef BPRODUCT_H
#define BPRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class BProduct
{
protected:
    string id, name;
    int price;
    int quantity;
public:
    // getSpecificProducts(), egyik megoldashoz:
    BProduct()=default;

    BProduct(const string& id,
             const string& name,
             int price,
             int quantity);
    virtual ~BProduct()=default;

    const string& getId() const; // tobb feladathoz
    int getPrice() const; // ar-szamitas

    void setQuantity(int quantity); // tobb feladathoz
    int getQuantity() const; // tobb feladathoz

    const string& getName() const; // saveProducts()

    virtual string type() const=0;
    virtual void print(ostream& os) const;
};

ostream& operator<< (ostream& os, const BProduct& p);

#endif // BPRODUCT_H
