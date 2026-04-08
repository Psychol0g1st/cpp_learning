#ifndef EXAMPLE_H
#define EXAMPLE_H

#include "sequence.h"

class Example1 : public Sequence
{
public:
    Example1();
    int value(int index) const override;
};

class Example2 : public Sequence
{
public:
    Example2();
    int value(int index) const override;
};

#endif // EXAMPLE_H
