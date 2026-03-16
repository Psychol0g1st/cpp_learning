#include "course.h"

#include <iostream>
using namespace std;

Course::Course(const string& name,
               int credits):
    name(name),
    credits(credits)
{
}

string Course::getName() const
{
    return name;
}

int Course::getCredits() const
{
    return credits;
}

void Course::print() const
{
    cout << name << " " << credits << " kredit" << endl;
}
