#include "coupon.h"

Coupon::Coupon(int value):
    value(value)
{
}

int Coupon::getValue() const
{
    return value;
}
