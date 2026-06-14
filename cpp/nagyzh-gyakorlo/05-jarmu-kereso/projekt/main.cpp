#include <iostream>
#include <vector>
using namespace std;

#include "garage.h"
#include "vehicle.h"

int main() {
    Garage garage;
    garage.addVehicle(new Bike("B1", 120000, true));
    garage.addVehicle(new Bike("B2", 80000, false));
    garage.addVehicle(new Car("C1", 2500000, 5));
    garage.addVehicle(new Car("C2", 4000000, 7));
    garage.addVehicle(new Truck("T1", 9000000, 7.5));

    cout << "Electric bikes:" << endl;
    vector<Bike*> bikes = garage.getElectricBikes();
    for (size_t i = 0; i < bikes.size(); i++) {
        bikes[i]->print();
    }

    cout << "Cars with at least 6 seats:" << endl;
    vector<Car*> cars = garage.getCarsWithAtLeastSeats(6);
    for (size_t i = 0; i < cars.size(); i++) {
        cars[i]->print();
    }

    cout << "Cheap vehicle count: " << garage.countCheaperThan(200000) << endl;
    return 0;
}
