#ifndef FURNITURE_H
#define FURNITURE_H

#include <string>
using namespace std;

class Furniture
{
protected:
    string id;
    string woodType;
    double weight;
    int width, height, length;
    int price;
public:
    Furniture(const string& id,
              const string& woodType,
              double weight,
              int width, int height, int length,
              int price);
    virtual ~Furniture()=default;

    const string& getId() const;
    int getPrice() const;

    virtual void print() const=0;
};

#endif // FURNITURE_H
