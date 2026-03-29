#ifndef EXAMPLE_H
#define EXAMPLE_H

#include "canvas.h"

class Example1 : public Canvas
{
public:
    Example1();
    char cell(int x, int y) const override;
};

class Example2 : public Canvas
{
public:
    Example2();
    char cell(int x, int y) const override;
};

#endif // EXAMPLE_H
