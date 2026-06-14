#ifndef BCLOTHES_H
#define BCLOTHES_H

#include "bproduct.h"

class BClothes : public BProduct
{
    string size;
public:
    // getSpecificProducts(), egyik megoldashoz:
    BClothes()=default;

    BClothes(const string& id,
             const string& name,
             int price,
             int quantity,
             const string& size);

    const string& getSize() const; // saveProducts()

    string type() const;
    void print(ostream& os) const;
};

#endif // BCLOTHES_H
