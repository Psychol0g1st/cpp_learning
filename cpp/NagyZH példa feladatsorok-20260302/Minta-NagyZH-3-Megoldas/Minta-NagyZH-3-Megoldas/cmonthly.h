#ifndef CMONTHLY_H
#define CMONTHLY_H

#include "coupon.h"

class CMonthly : public Coupon
{
    static int currentYear;
    static int currentMonth;
    static int currentDay;

    int year, month;
public:
    CMonthly(int value, int year, int month);

    bool isValid() const;
    void use();

    static void setCurrentDate(int y, int m, int d);
};

#endif // CMONTHLY_H
