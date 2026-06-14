#include "fwardrobe.h"

#include <iostream>
using namespace std;

FWardrobe::FWardrobe(const string &id,
                     const string &woodType,
                     double weight,
                     int width, int height, int length,
                     int price,
                     int doorCount,
                     bool hasMirror):
    Furniture(id,woodType,weight,width,height,length,price),
    doorCount(doorCount),
    hasMirror(hasMirror)
{
}

void FWardrobe::print() const
{
    cout << "Wardrobe";
    cout << " \"" << id << "\":";
    cout << " " << woodType;
    cout << ", " << weight << "kg";
    cout << ", " << width << "x" << height << "x" << length;
    cout << ", " << price << "Ft";
    cout << ", doors: " << doorCount;
    cout << ", mirror: " << (hasMirror ? "Yes" : "No");
    cout << endl;
}
