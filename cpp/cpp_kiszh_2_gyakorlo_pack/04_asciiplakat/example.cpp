#include "example.h"

Example1::Example1():
    Canvas(9,5)
{
}

char Example1::cell(int x, int y) const
{
    return (x==y) ? 'X' : '.';
}

Example2::Example2():
    Canvas(9,5)
{
}

char Example2::cell(int x, int y) const
{
    return (y==2 || x==4) ? '+' : '.';
}
