#include "parcel.h"

#include <iostream>
using namespace std;

Parcel::Parcel():
    weight(0.0),
    priority(false)
{
}

Parcel::Parcel(double weight,
               bool priority):
    weight(weight),
    priority(priority)
{
}

double Parcel::getWeight() const
{
    return weight;
}

bool Parcel::isPriority() const
{
    return priority;
}

void Parcel::print() const
{
    cout << weight << " kg (" << (priority ? "priority" : "standard") << ")" << endl;
}
