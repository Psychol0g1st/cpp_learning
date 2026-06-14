#ifndef FTABLE_H
#define FTABLE_H

#include "furniture.h"

class FTable : public Furniture
{
    int legCount;
    bool legsAdjustable;
public:
    FTable(const string& id,
           const string& woodType,
           double weight,
           int width, int height, int length,
           int price,
           int legCount,
           bool legsAdjustable);

    void print() const;
};

#endif // FTABLE_H
