#ifndef STORE_H
#define STORE_H

#include <vector>
using namespace std;

#include "furniture.h"
#include "order.h"

class Store
{
    static int administrationFee;

    vector<Furniture*> products;
    vector<int> quantities;
public:
    Store()=default;
    ~Store();

    void loadStock(const string& filePath);
    void printProducts() const;
    void printStock() const;
    static Order loadOrder(const string &filePath);
    int priceOfOrder(const Order& order) const;
    bool deliverOrder(const Order& order);
    void produce(const string& id, int quantity);
    void exportQuantities(const string& filePath) const;

    static void setAdministrationFee (int administrationFee);
private:
    size_t indexOf (const string& productId) const;
};

#endif // STORE_H
