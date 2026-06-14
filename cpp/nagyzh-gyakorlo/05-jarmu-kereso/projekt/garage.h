#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
using namespace std;

#include "vehicle.h"

class Garage {
    vector<Vehicle*> vehicles;
public:
    Garage() = default;
    ~Garage();

    void addVehicle(Vehicle* vehicle);
    void printAll() const;
    int getTotalPrice() const;
};

#endif
