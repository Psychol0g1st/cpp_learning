#include <iostream>
#include <string>
using namespace std;

class Product {
    string id;
    string name;
    int price;
public:
    Product(string id, string name, int price) {
        id = id;
        name = name;
        price = price;
    }

    int getName() const {
        return name;
    }

    int getPrice() {
        return price;
    }
};

int main() {
    Product p1("P1", "Asztal", 12000);
    Product p2("P2", "Szek", 8000);

    cout << "#" << p1.id << ": " << p1.getName() << ", " << p1.getPrice() << " Ft" << endl;
    cout << "#" << p2.id << ": " << p2.getName() << ", " << p2.getPrice() << " Ft" << endl;
    cout << "Total: " << p1.getPrice() + p2.getPrice() << endl;
}
