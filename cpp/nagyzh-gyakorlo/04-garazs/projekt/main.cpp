#include <iostream>
using namespace std;

#include "garage.h"
#include "vehicle.h"

int main() {
    Garage garage;
    garage.addVehicle(new Bike("B1", 120000, true));
    garage.addVehicle(new Car("C1", 2500000, 5));
    garage.addVehicle(new Truck("T1", 9000000, 7.5));

    garage.printAll();
    cout << "Total price: " << garage.getTotalPrice() << endl;
    return 0;
}
