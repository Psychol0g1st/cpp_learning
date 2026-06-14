#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
using namespace std;

#include "bproduct.h"
#include "shipment.h"

class Warehouse
{
    vector<BProduct*> products;
public:
    Warehouse()=default;
    ~Warehouse();

    void loadProducts (const string& type,
                      const string& filePath);

    // itt lehet (es ajanlott) a ref return
    const vector<BProduct*>& getProducts() const;

    // itt nem lehet ref return (helyben konstrualt ertek)
    vector<BProduct*> getProducts(const string& type) const;

    template <class T>
    vector<T*> getSpecificProducts(int minPrice,
                                    int maxPrice) const
    {
        vector<T*> result;
        for (size_t i=0;i<products.size();i++)
        {
            if (minPrice<=products[i]->getPrice() &&
                maxPrice>=products[i]->getPrice())
            {
                T* child = dynamic_cast<T*>(products[i]);
                if (child)
                    result.push_back(child);
            }
        }
        return result;
    }

    template <class T>
    vector<T*> getSpecificProducts2(int minPrice,
                                     int maxPrice) const
    {
        T example; // kell parameter nelkuli ctor minden gyerekbe!
        vector<T*> result;
        for (size_t i=0;i<products.size();i++)
            if (products[i]->type() == example.type())
                if (minPrice<=products[i]->getPrice() &&
                    maxPrice>=products[i]->getPrice())
                    result.push_back((T*)products[i]);
        return result;
    }

    void deliverShipment (const Shipment& shipment);

    bool makeOrder (const string& id,
                   int quantity,
                   int& customerMoney);

    void saveProducts(const string& type,
                      const string& filePath) const;
private:
    BProduct* get (const string& id) const;
};

#endif // WAREHOUSE_H
