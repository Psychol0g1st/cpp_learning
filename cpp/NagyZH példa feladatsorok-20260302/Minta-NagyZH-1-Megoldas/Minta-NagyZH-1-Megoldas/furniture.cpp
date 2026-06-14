#include "furniture.h"

Furniture::Furniture(const string &id,
                     const string &woodType,
                     double weight,
                     int width, int height, int length,
                     int price):
    id(id),
    woodType(woodType),
    weight(weight),
    width(width),
    height(height),
    length(length),
    price(price)
{
}

const string &Furniture::getId() const
{
    return id;
}

int Furniture::getPrice() const
{
    return price;
}
