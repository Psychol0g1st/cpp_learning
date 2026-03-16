#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "parcelday.h"
#include "courierday.h"
#include "parcel.h"
#endif

struct TesterGuard
{
    string partname;
    TesterGuard (const string& partname);
    ~TesterGuard();
};

namespace LogisticsTools {}
using namespace LogisticsTools;

int main()
{
    cout << "main() eleje!" << endl;
    cout << fixed << setprecision(2); // sets output format

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        ParcelDay pd("Eszter", "Del", 3);
        if (!is_base_of<CourierDay,ParcelDay>::value)
            cout << "Hiba: A CourierDay nem a ParcelDay ose.";
        else
            cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        ParcelDay pd("Bela", "Nyugat", 2);
        pd.setParcel(0, Parcel(2.5, true));
        pd.setParcel(1, Parcel(7.0, false));
        cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        ParcelDay pd1("Anna", "Kozpont", 3);
        pd1.setParcel(0, Parcel(1.2, true));
        pd1.setParcel(1, Parcel(3.5, false));
        pd1.setParcel(2, Parcel(2.8, true));
        ParcelDay pd2("Miklos", "Kelet", 2);
        pd2.setParcel(0, Parcel(9.0, false));
        pd2.setParcel(1, Parcel(4.4, false));
        pd1.print();
        cout << endl;
        pd2.print();
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        ParcelDay pd1("A", "X", 3);
        pd1.setParcel(0, Parcel(2.5, true));
        pd1.setParcel(1, Parcel(3.0, false));
        pd1.setParcel(2, Parcel(4.5, true));
        ParcelDay pd2("B", "Y", 2);
        pd2.setParcel(0, Parcel(10.0, false));
        pd2.setParcel(1, Parcel(6.5, true));
        cout << pd1.getTotalWeight() << endl;
        cout << pd2.getTotalWeight() << endl;
    }//
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        cout << ParcelDay::getHeavyDayLimit() << endl;
        ParcelDay::setHeavyDayLimit(18.5);
        cout << ParcelDay::getHeavyDayLimit() << endl;
        ParcelDay::setHeavyDayLimit(25.0);
        cout << ParcelDay::getHeavyDayLimit() << endl;
    }//
#endif

#ifdef PART6
    {
        TesterGuard tguard("PART6");
        ParcelDay pd1("A", "X", 3); // total: 27.0
        pd1.setParcel(0, Parcel(10.0, false));
        pd1.setParcel(1, Parcel(8.0, true));
        pd1.setParcel(2, Parcel(9.0, false));
        ParcelDay pd2("B", "Y", 3); // total: 18.0
        pd2.setParcel(0, Parcel(5.0, false));
        pd2.setParcel(1, Parcel(6.0, false));
        pd2.setParcel(2, Parcel(7.0, true));
        ParcelDay pd3("C", "Z", 4); // total: 9.5
        pd3.setParcel(0, Parcel(1.0, false));
        pd3.setParcel(1, Parcel(2.0, false));
        pd3.setParcel(2, Parcel(3.0, true));
        pd3.setParcel(3, Parcel(3.5, false));
        for (double level : {25.0, 10.0, 30.0})
        {
            ParcelDay::setHeavyDayLimit(level);
            cout << "minimum: " << level << " ->" << flush;
            for (auto pd_addr : {&pd1, &pd2, &pd3})
            {
                const ParcelDay& pd = *pd_addr;
                bool ok = pd.isHeavyDay();
                cout << " " << ok << flush;
            }
            cout << endl;
        }
        ParcelDay::setHeavyDayLimit(25.0);
    }//
#endif

#ifdef PART7
    {
        TesterGuard tguard("PART7");
        if (is_same<ParcelDay,LogisticsTools::ParcelDay>::value)
            cout << "Nevter rendben!" << endl;
        else
            cout << "ParcelDay nincs a nevterben!" << endl;
    }//
#endif

    cout << "main() vege!" << endl;
    return 0;
}

TesterGuard::TesterGuard(const string &p):
    partname(p)
{
    cout << endl << "----START OF " << partname << "----" << endl << endl;
}

TesterGuard::~TesterGuard()
{
    cout << endl << "----END OF " << partname << "----" << endl << endl;
}
