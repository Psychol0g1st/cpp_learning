#include "courierday.h"

#include <iostream>
using namespace std;

CourierDay::CourierDay(const string& courierName,
                       const string& region):
    courierName(courierName),
    region(region)
{
}

string CourierDay::getCourierName() const
{
    return courierName;
}

string CourierDay::getRegion() const
{
    return region;
}

void CourierDay::print() const
{
    cout << courierName << " @ " << region << endl;
}
