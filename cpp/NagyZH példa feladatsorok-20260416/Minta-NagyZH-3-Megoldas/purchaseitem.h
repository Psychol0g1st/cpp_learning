#ifndef PURCHASEITEM_H
#define PURCHASEITEM_H

#include <string>
using namespace std;

class PurchaseItem
{
    string name;
    int unitPrice;
    double qValue;
    string qUnit;
public:
    PurchaseItem(const string& name,
                 int unitPrice,
                 double qValue,
                 const string& qUnit);

    void print() const;

    double getTotalPrice() const;
};

#endif // PURCHASEITEM_H
