#include "canvas.h"

#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height):
    width(width),
    height(height)
{
}

int Canvas::getWidth() const
{
    return width;
}

int Canvas::getHeight() const
{
    return height;
}

void Canvas::print() const
{
    cout << width << " " << height << endl;
    for (int y=0; y<height; y++)
    {
        for (int x=0; x<width; x++)
            cout << cell(x,y) << flush;
        cout << endl;
    }
}

// PART5: ird fajlba ugyanazt, mint amit a print() kiir.
