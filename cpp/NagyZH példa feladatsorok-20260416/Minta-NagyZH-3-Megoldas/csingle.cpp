#include "csingle.h"

CSingle::CSingle(int value):
    Coupon(value)
{
}

bool CSingle::isValid() const
{
    return valid;
}

void CSingle::use()
{
    valid = false;
}
