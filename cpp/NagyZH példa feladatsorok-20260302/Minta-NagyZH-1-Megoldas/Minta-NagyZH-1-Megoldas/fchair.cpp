#include "fchair.h"

#include <iostream>
using namespace std;

FChair::FChair(const string &id,
               const string &woodType,
               double weight,
               int width, int height, int length,
               int price,
               const string &style):
    Furniture(id,woodType,weight,width,height,length,price),
    style(style)
{
}

void FChair::print() const
{
    cout << "Chair";
    cout << " \"" << id << "\":";
    cout << " " << woodType;
    cout << ", " << weight << "kg";
    cout << ", " << width << "x" << height << "x" << length;
    cout << ", " << price << "Ft";
    cout << ", style: " << style;
    cout << endl;
}
