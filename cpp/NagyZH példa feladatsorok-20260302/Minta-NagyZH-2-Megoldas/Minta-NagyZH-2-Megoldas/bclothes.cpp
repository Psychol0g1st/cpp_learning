#include "bclothes.h"

BClothes::BClothes(const string &id,
                   const string &name,
                   int price,
                   int quantity,
                   const string &size):
    BProduct(id,name,price,quantity),
    size(size)
{
}

const string &BClothes::getSize() const
{
    return size;
}

string BClothes::type() const
{
    return "clothes";
}

void BClothes::print(ostream &os) const
{
    BProduct::print(os);
    os << ", size: " << size;
}
