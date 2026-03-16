#ifndef ROUTE_H
#define ROUTE_H

#include <string>
using namespace std;

class Route
{
    string from;
    string to;
public:
    Route(const string& from,
          const string& to);

    string getFrom() const;
    string getTo() const;

    void print() const;
};

#endif // ROUTE_H
