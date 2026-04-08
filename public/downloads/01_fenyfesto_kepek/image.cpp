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
        {
            bool p = pixel(x,y);
            cout << (p ? '.' : '#') << flush;
        }
        cout << endl;
    }
}

// PART5 feladat: definiald ezt a fuggvenyt ugy,
// hogy ugyanazt a szoveges formatumot irja fajlba,
// mint amit a print() a szabvanyos kimenetre.
