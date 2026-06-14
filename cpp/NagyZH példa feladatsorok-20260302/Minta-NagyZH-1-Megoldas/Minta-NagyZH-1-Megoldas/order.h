#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
using namespace std;

// lehetne kulon OrderItem osztaly, amiben van id, quantity
class Order
{
    vector<string> ids;
    vector<int> quantities;
public:
    Order()=default;

    void addProduct (const string& id, int quantity);

    size_t getSize() const;
    const string& getId (size_t index) const;
    int getQuantity (size_t index) const;
};

#endif // ORDER_H
