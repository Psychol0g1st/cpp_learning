#ifndef STATION_H
#define STATION_H

#include <string>
using namespace std;

class Station
{
    string city;
    string code;
public:
    Station(const string& city,
            const string& code);

    string getCity() const;
    string getCode() const;

    void print() const;
};

#endif // STATION_H
