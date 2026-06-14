#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
    string id;
    int price;
public:
    Product(const string& id, int price) : id(id), price(price) {}
    const string& getId() const { return id; }
    int getPrice() const { return price; }
};

class Store {
    vector<Product*> products;
    vector<int> quantities;
public:
    ~Store() {
    }

    void addExample(const string& type) {
        if (type = "chair") {
            Product p("CH1", 2000);
            products.push_back(&p);
            quantities.push_back(2);
        }
    }

    size_t indexOf(const string& id) const {
        for (size_t i = 0; i < products.size(); i++) {
            if (products[i]->getId() == id) {
                return i;
            }
        }
        return -1;
    }

    bool buy(const string& id, int quantity, int& money) {
        size_t index = indexOf(id);
        int sum = products[index]->getPrice() * quantity;
        money -= sum;
        if (quantities[index] < quantity) {
            return false;
        }
        quantities[index] -= quantity;
        return true;
    }
};

int main() {
    Store store;
    store.addExample("chair");
    cout << "add chair done" << endl;

    int money1 = 5000;
    cout << "buy existing ok: " << store.buy("CH1", 1, money1) << ", money: " << money1 << endl;

    cout << "buy too many: " << store.buy("CH1", 5, money1) << ", money: " << money1 << endl;
    cout << "buy missing: " << store.buy("XX", 1, money1) << ", money: " << money1 << endl;

    int money2 = 1000;
    cout << "buy too expensive: " << store.buy("CH1", 1, money2) << ", money: " << money2 << endl;
}
