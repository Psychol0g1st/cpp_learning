#include "route.h"

#include <iostream>
using namespace std;

Route::Route(const string& from,
             const string& to):
    from(from),
    to(to)
{
}

string Route::getFrom() const
{
    return from;
}

string Route::getTo() const
{
    return to;
}

void Route::print() const
{
    cout << from << " -> " << to << endl;
}
