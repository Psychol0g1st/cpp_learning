#include "bchair.h"

BChair::BChair(const string &id,
               const string &name,
               int price,
               int quantity,
               bool canBeSet):
    BProduct(id,name,price,quantity),
    canBeSet(canBeSet)
{
}

bool BChair::getCanBeSet() const
{
    return canBeSet;
}

string BChair::type() const
{
    return "chair";
}

void BChair::print(ostream &os) const
{
    BProduct::print(os);
    os << ", can be set? ";
    os << (canBeSet ? "Yes" : "No");
}
