#ifndef CMULTI_H
#define CMULTI_H

#include "coupon.h"

class CMulti : public Coupon
{
    // eleg lenne csak a usesLeft
    int totalUses, usesLeft;
public:
    CMulti(int value, int totalUses);

    bool isValid() const;
    void use();
};

#endif // CMULTI_H
