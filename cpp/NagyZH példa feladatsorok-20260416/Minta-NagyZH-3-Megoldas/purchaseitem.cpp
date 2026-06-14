#include "purchaseitem.h"

#include <iostream>
using namespace std;

PurchaseItem::PurchaseItem(const string &name,
                           int unitPrice,
                           double qValue,
                           const string& qUnit):
    name(name),
    unitPrice(unitPrice),
    qValue(qValue),
    qUnit(qUnit)
{
}

void PurchaseItem::print() const
{
    cout << "[" << name;
    cout << ", " << unitPrice;
    cout << " x " << qValue;
    cout << " " << qUnit;
    cout << "]";
    cout << endl;
}

double PurchaseItem::getTotalPrice() const
{
    return qValue * unitPrice;
}
