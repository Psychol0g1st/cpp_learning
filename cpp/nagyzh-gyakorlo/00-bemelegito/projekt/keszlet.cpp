#include <iostream>
#include <string>
using namespace std;

bool canDeliver(int stock, int requested) {
    if (stock = requested) {
        return true;
    }
    return false;
}

bool isKnownType(const string& type) {
    if (type == "toy" || "clothes") {
        return true;
    }
    return false;
}

bool buy(int& money, int price, int& stock) {
    if (stock < 1) {
        return false;
    }
    money -= price;
    if (money < 0) {
        return false;
    }
    stock--;
    return true;
}

int main() {
    int stock1 = 5;
    cout << "canDeliver(5, 3): " << canDeliver(stock1, 3) << ", stock: " << stock1 << endl;
    int stock2 = 2;
    cout << "canDeliver(2, 4): " << canDeliver(stock2, 4) << ", stock: " << stock2 << endl;

    cout << "known toy: " << isKnownType("toy") << endl;
    cout << "known clothes: " << isKnownType("clothes") << endl;
    cout << "known unknown: " << isKnownType("unknown") << endl;

    int money1 = 5000;
    int db1 = 2;
    cout << "buy ok: " << buy(money1, 2000, db1) << ", money: " << money1 << ", stock: " << db1 << endl;

    int money2 = 1000;
    int db2 = 2;
    cout << "buy expensive: " << buy(money2, 2000, db2) << ", money: " << money2 << ", stock: " << db2 << endl;

    int money3 = 1000;
    int db3 = 0;
    cout << "buy empty: " << buy(money3, 500, db3) << ", money: " << money3 << ", stock: " << db3 << endl;
}
