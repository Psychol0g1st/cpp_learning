#include "example.h"

Example1::Example1():
    Image(7,4)
{
}

bool Example1::pixel(int x, int y) const
{
    return x==0 || y==0;
}

Example2::Example2():
    Image(9,5)
{
}

bool Example2::pixel(int x, int y) const
{
    return (x+y)%3==0;
}
