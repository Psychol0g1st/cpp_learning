#ifndef PURCHASE_H
#define PURCHASE_H

#include <vector>
using namespace std;

#include "purchaseitem.h"
#include "wallet.h"

class Purchase
{
    vector<PurchaseItem> items;
public:
    Purchase(const string& filePath);

    void print() const;
    int getTotal() const;
    int useCoupons(Wallet& wallet) const;

};

#endif // PURCHASE_H
