#include "vehicle.h"

int main() {
    Bike b("B1", 120000, true);
    Car c("C1", 2500000, 5);
    Truck t("T1", 9000000, 7.5);

    b.print();
    c.print();
    t.print();
    return 0;
}
