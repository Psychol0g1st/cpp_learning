#ifndef BTOY_H
#define BTOY_H

#include "bproduct.h"

class BToy : public BProduct
{
    int age;
public:
    // getSpecificProducts(), egyik megoldashoz:
    BToy()=default;

    BToy(const string& id,
         const string& name,
         int price,
         int quantity,
         int age);

    int getAge() const; // saveProducts()

    string type() const;
    void print(ostream& os) const;
};

#endif // BTOY_H
