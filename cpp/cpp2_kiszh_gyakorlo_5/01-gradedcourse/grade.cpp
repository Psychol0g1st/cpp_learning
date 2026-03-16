#include "grade.h"

#include <iostream>
using namespace std;

Grade::Grade():
    points(0),
    note("<HIANYZO JEGY>")
{
}

Grade::Grade(int points,
             const string& note):
    points(points),
    note(note)
{
}

int Grade::getPoints() const
{
    return points;
}

const string& Grade::getNote() const
{
    return note;
}

void Grade::print() const
{
    cout << points << " pont - " << note << endl;
}
