#include "station.h"

#include <iostream>
using namespace std;

Station::Station(const string& city,
                 const string& code):
    city(city),
    code(code)
{
}

string Station::getCity() const
{
    return city;
}

string Station::getCode() const
{
    return code;
}

void Station::print() const
{
    cout << city << " [" << code << "]" << endl;
}
