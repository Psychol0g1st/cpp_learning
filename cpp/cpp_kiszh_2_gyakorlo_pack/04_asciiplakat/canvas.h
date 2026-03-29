#ifndef CANVAS_H
#define CANVAS_H

#include <string>
#include <fstream>
using namespace std;

class Canvas
{
protected:
    int width, height;
public:
    Canvas(int width, int height);
    virtual ~Canvas()=default;

    int getWidth() const;
    int getHeight() const;

    // '.' jelenti az ures helyet
    virtual char cell(int x, int y) const = 0;

    void print() const;
    void saveToFile(const string& path) const;
};

#endif // CANVAS_H
