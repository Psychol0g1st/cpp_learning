#ifndef FCHAIR_H
#define FCHAIR_H

#include "furniture.h"

class FChair : public Furniture
{
    string style;
public:
    FChair(const string& id,
           const string& woodType,
           double weight,
           int width, int height, int length,
           int price,
           const string& style);

    void print() const;
};

#endif // FCHAIR_H
