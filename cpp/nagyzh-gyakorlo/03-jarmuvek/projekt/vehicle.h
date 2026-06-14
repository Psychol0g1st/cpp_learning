#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
protected:
    string id;
    int price;
public:
    Vehicle(const string& id, int price);
    virtual ~Vehicle() = default;

    const string& getId() const;
    int getPrice() const;

    virtual void print() const = 0;
};

class Bike : public Vehicle {
    bool electric;
public:
    Bike(const string& id, int price, bool electric);
    bool isElectric() const;
    void print() const override;
};

class Car : public Vehicle {
    int seats;
public:
    Car(const string& id, int price, int seats);
    int getSeats() const;
    void print() const override;
};

class Truck : public Vehicle {
    double capacity;
public:
    Truck(const string& id, int price, double capacity);
    double getCapacity() const;
    void print() const override;
};

#endif
