#ifndef CROSS_H
#define CROSS_H
#include "image.h"

using namespace std;

class Cross : public Image
{
protected:

public:
    Cross();
    ~Cross();

    bool pixel(int x, int y) const override;
};

#endif // CROSS_H
