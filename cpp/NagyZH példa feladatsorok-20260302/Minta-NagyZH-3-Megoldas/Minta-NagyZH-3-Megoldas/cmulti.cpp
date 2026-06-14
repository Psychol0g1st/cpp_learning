#include "cmulti.h"

CMulti::CMulti(int value, int totalUses):
    Coupon(value),
    totalUses(totalUses),
    usesLeft(totalUses)
{
}

bool CMulti::isValid() const
{
    return usesLeft>0;
}

void CMulti::use()
{
    usesLeft--;
}
