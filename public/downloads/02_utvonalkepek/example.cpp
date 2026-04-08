#include "example.h"

Example1::Example1():
    Image(8,5)
{
}

bool Example1::pixel(int x, int y) const
{
    return x==y || x+y==7;
}

Example2::Example2():
    Image(10,4)
{
}

bool Example2::pixel(int x, int y) const
{
    return y%2==0 && x>1 && x<8;
}
