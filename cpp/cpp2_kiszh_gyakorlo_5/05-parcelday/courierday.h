#ifndef COURIERDAY_H
#define COURIERDAY_H

#include <string>
using namespace std;

class CourierDay
{
    string courierName;
    string region;
public:
    CourierDay(const string& courierName,
               const string& region);

    string getCourierName() const;
    string getRegion() const;

    void print() const;
};

#endif // COURIERDAY_H
