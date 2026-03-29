#include "image.h"

#include <iostream>
using namespace std;

Image::Image(int width, int height):
    width(width),
    height(height)
{
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

void Image::print() const
{
    cout << width << " " << height << endl;
    for (int y=0; y<height; y++)
    {
        for (int x=0; x<width; x++)
            cout << (pixel(x,y) ? '.' : '#') << flush;
        cout << endl;
    }
}

// PART5: ird meg a print()-tel megegyezo fajlkimenetet.
