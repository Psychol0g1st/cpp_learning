#include "team.h"

#include <iostream>
using namespace std;

Team::Team(const string& name,
           const string& city):
    name(name),
    city(city)
{
}

string Team::getName() const
{
    return name;
}

string Team::getCity() const
{
    return city;
}

void Team::print() const
{
    cout << city << " - " << name << endl;
}
