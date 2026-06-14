#include <iostream>
using namespace std;

#include "store.h"
#include "order.h"

int main()
{
    cout << "main() eleje!" << endl << endl;

    Store store;
    store.loadStock("stock.json");

    cout << "---All products---" << endl;
    store.printProducts();
    cout << endl;

    cout << "---Current stock---" << endl;
    store.printStock();
    cout << endl;

    Order o1 = Store::loadOrder("order1.json");
    Order o2 = Store::loadOrder("order2.json");
    Order o3 = Store::loadOrder("order3.json");

    cout << "Price of order 1: " << store.priceOfOrder(o1) << endl;
    cout << "Price of order 2: " << store.priceOfOrder(o2) << endl;
    cout << "Price of order 3: " << store.priceOfOrder(o3) << endl;

    bool success1 = store.deliverOrder(o1);
    bool success2 = store.deliverOrder(o2);
    bool success3 = store.deliverOrder(o3);
    cout << "Order 1 delivered? " << success1 << endl;
    cout << "Order 2 delivered? " << success2 << endl;
    cout << "Order 3 delivered? " << success3 << endl;
    cout << "---Current stock after deliveries---" << endl;
    store.printStock();
    cout << endl;

    store.produce("CH-oak-x321", 4);
    store.produce("WR-mahogany-k4m6", 5);
    store.produce("TB-cherry-234k", 2);
    cout << "---Current stock after production---" << endl;
    store.printStock();
    cout << endl;

    store.exportQuantities("stock-exported.json");

    cout << "main() vege!" << endl;
    return 0;
}
