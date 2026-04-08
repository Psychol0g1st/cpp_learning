#include "example.h"

Example1::Example1():
    Image(8,4)
{
}

bool Example1::pixel(int x, int y) const
{
    return x==1 || x==6 || y==2;
}

Example2::Example2():
    Image(9,5)
{
}

bool Example2::pixel(int x, int y) const
{
    return x%2==0 && y%2==0;
}
