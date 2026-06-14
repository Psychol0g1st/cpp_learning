#ifndef COUPON_H
#define COUPON_H

class Coupon
{
    int value;
public:
    Coupon(int value);
    virtual ~Coupon()=default;

    int getValue() const;

    virtual bool isValid() const=0;
    virtual void use()=0;
};

#endif // COUPON_H
