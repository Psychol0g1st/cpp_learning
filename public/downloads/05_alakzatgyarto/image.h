#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream>
using namespace std;

class Image
{
protected:
    int width, height;
public:
    Image(int width, int height);
    virtual ~Image()=default;

    int getWidth() const;
    int getHeight() const;

    virtual bool pixel(int x, int y) const = 0;

    void print() const;
    void saveToFile(const string& path) const;
};

#endif // IMAGE_H
