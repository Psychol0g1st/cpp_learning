#ifndef CSINGLE_H
#define CSINGLE_H

#include "coupon.h"

class CSingle : public Coupon
{
    bool valid=true;
public:
    CSingle(int value);

    bool isValid() const;
    void use();
};

#endif // CSINGLE_H
