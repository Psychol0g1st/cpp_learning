#ifndef PARCEL_H
#define PARCEL_H

class Parcel
{
    double weight;
    bool priority;
public:
    Parcel();
    Parcel(double weight,
           bool priority);

    double getWeight() const;
    bool isPriority() const;

    void print() const;
};

#endif // PARCEL_H
