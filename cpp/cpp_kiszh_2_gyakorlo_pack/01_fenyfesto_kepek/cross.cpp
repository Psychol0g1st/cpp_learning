#include "cross.h"

    Cross::Cross(): Image(9,9){

    }
    Cross::~Cross(){}

    bool Cross::pixel(int x, int y) const {
        return x == 4 || y == 4;
    }

