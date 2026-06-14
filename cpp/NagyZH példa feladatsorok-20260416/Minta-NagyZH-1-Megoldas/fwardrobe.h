#ifndef FWARDROBE_H
#define FWARDROBE_H

#include "furniture.h"

class FWardrobe : public Furniture
{
    int doorCount;
    bool hasMirror;
public:
    FWardrobe(const string& id,
              const string& woodType,
              double weight,
              int width, int height, int length,
              int price,
              int doorCount,
              bool hasMirror);

    void print() const;
};

#endif // FWARDROBE_H
