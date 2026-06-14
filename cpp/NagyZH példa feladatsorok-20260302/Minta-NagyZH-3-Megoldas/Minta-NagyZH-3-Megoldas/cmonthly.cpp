#include "cmonthly.h"

int CMonthly::currentYear = 2024;
int CMonthly::currentMonth = 5;
int CMonthly::currentDay = 1;

CMonthly::CMonthly(int value, int year, int month):
    Coupon(value),
    year(year),
    month(month)
{
}

bool CMonthly::isValid() const
{
    return year==currentYear && month==currentMonth;
}

void CMonthly::use()
{
}

void CMonthly::setCurrentDate(int y, int m, int d)
{
    currentYear = y;
    currentMonth = m;
    currentDay = d;
}
