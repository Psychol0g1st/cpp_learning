#ifndef BCHAIR_H
#define BCHAIR_H

#include "bproduct.h"

class BChair : public BProduct
{
    bool canBeSet;
public:
    // getSpecificProducts(), egyik megoldashoz:
    BChair()=default;

    BChair(const string& id,
           const string& name,
           int price,
           int quantity,
           bool canBeSet);

    bool getCanBeSet() const; // saveProducts()

    string type() const;
    void print(ostream& os) const;
};

#endif // BCHAIR_H
