#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
using namespace std;

#include "coupon.h"

class Wallet
{
    vector<Coupon*> coupons;
public:
    Wallet();
    ~Wallet();

    void addCoupon (Coupon* newCoupon);

    int useAllAndGetTotalDiscount();

    void loadCoupons (const string& filePath);

    template <class T>
    int countCoupons(bool onlyValid=false) const
    {
        int count=0;
        for (size_t i=0;i<coupons.size();i++)
            if (dynamic_cast<T*>(coupons[i]))
                if (!onlyValid || coupons[i]->isValid())
                    count++;
        return count;
    }

    void exportCounts(const string &filePath) const;
};

#endif // WALLET_H
