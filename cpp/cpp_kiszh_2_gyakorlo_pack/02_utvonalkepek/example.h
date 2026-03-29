#ifndef EXAMPLE_H
#define EXAMPLE_H

#include "image.h"

class Example1 : public Image
{
public:
    Example1();
    bool pixel(int x, int y) const override;
};

class Example2 : public Image
{
public:
    Example2();
    bool pixel(int x, int y) const override;
};

#endif // EXAMPLE_H
