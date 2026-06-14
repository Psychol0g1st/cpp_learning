#include <iostream>
using namespace std;

// sajat include-ok (az osztalyok szabadon atnevezhetok!)
#include "wallet.h"
#include "csingle.h"
#include "cmulti.h"
#include "cmonthly.h"
#include "purchase.h"
using SingleCoupon = CSingle;
using MultiCoupon = CMulti;
using MonthlyCoupon = CMonthly;

int main()
{
    cout << "main() eleje!" << endl << endl;

    Wallet wallet;

    // itt kell a Wallet-et feltolteni a harom kuponnal:
    wallet.addCoupon(new SingleCoupon(1000));
    wallet.addCoupon(new MultiCoupon(2000,5));
    wallet.addCoupon(new MonthlyCoupon(3000,2024,5));

    cout << "---Vasarlasok, print()" << endl;
    Purchase purchase("purchases.json");
    purchase.print();
    cout << endl;

    cout << "---Vegosszeg lekerdezese (alap)" << endl;
    cout << "sum == " << purchase.getTotal() << endl; // 15831
    cout << endl;

    cout << "---Vegosszeg lekerdezese (kuponok hasznalata)" << endl;
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 9831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 10831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
    cout << endl;

    cout << "---Datum atallitasa, havi kuponok" << endl;
    // nem kotelezo ezt a statikus fuggvenyt hasznalni, ez csak pelda
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
    MonthlyCoupon::setCurrentDate(2023,12,31);
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 15831
    MonthlyCoupon::setCurrentDate(2024,5,1);
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 12831
    cout << endl;

    // Az alabbi tesztelendo sorok kozul szabadon lehet valogatni!
    //
    cout << "---loadCoupons(), countCoupons(), exportCounts()" << endl;
    cout << ">>> Beolvasas: coupons-1.json ..." << endl;
    wallet.loadCoupons("coupons-1.json");
    wallet.exportCounts("export-example-A.json");
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 2 // egyszeri, ervenyes
    cout << wallet.countCoupons<SingleCoupon>() << endl; // 3 // egyszeri, mind
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 4091
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 0 // egyszeri, ervenyes
    cout << wallet.countCoupons<MonthlyCoupon>() << endl; // 3 // havi, mind
    cout << wallet.countCoupons<MultiCoupon>(true) << endl; // 2 // tobbszori, ervenyes
    cout << ">>> Beolvasas: coupons2.json ..." << endl;
    wallet.loadCoupons("coupons-2.json");
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 2 // egyszeri, ervenyes
    cout << wallet.countCoupons<MultiCoupon>(true) << endl; // 6 // tobbszori, ervenyes
    cout << "sum == " << purchase.useCoupons(wallet) << endl; // 1141
    cout << wallet.countCoupons<SingleCoupon>(true) << endl; // 0 // egyszeri, ervenyes
    cout << wallet.countCoupons<MultiCoupon>(true) << endl; // 6 // tobbszori, ervenyes
    cout << wallet.countCoupons<MultiCoupon>(false) << endl; // 7 // tobbszori, mind
    wallet.exportCounts("export-example-B.json");
    cout << endl;

    cout << "main() vege!" << endl;
    return 0;
}
