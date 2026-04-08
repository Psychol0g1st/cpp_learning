#include "example.h"

Example1::Example1():
    Sequence(6)
{
}

int Example1::value(int index) const
{
    return 1 + 2*index;
}

Example2::Example2():
    Sequence(8)
{
}

int Example2::value(int index) const
{
    return (index*index) % 7;
}
