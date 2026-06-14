#include <iostream>
using namespace std;

#include "product.h"

int main() {
    Product p1("P1", "Szek", 14990);
    Product p2("P2", "Asztal", 39990);

    p1.print();
    p2.print();

    cout << "Total: " << p1.getPrice() + p2.getPrice() << endl;
    return 0;
}
