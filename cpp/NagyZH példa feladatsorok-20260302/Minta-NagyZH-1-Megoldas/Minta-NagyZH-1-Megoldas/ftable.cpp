#include "ftable.h"

#include <iostream>
using namespace std;

FTable::FTable(const string &id,
               const string &woodType,
               double weight,
               int width, int height, int length,
               int price,
               int legCount,
               bool legsAdjustable):
    Furniture(id,woodType,weight,width,height,length,price),
    legCount(legCount),
    legsAdjustable(legsAdjustable)
{
}

void FTable::print() const
{
    cout << "Table";
    cout << " \"" << id << "\":";
    cout << " " << woodType;
    cout << ", " << weight << "kg";
    cout << ", " << width << "x" << height << "x" << length;
    cout << ", " << price << "Ft";
    cout << ", legs: " << legCount;
    cout << (legsAdjustable ? " " : " non-") << "adjustable";
    cout << endl;
}
