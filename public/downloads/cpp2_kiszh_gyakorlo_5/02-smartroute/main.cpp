#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "smartroute.h"
#include "route.h"
#include "checkpoint.h"
#endif

struct TesterGuard
{
    string partname;
    TesterGuard (const string& partname);
    ~TesterGuard();
};

namespace NavigationTools {}
using namespace NavigationTools;

int main()
{
    cout << "main() eleje!" << endl;
    cout << fixed << setprecision(2); // sets output format

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        SmartRoute sr("Budapest", "Pecs", 3);
        if (!is_base_of<Route,SmartRoute>::value)
            cout << "Hiba: A Route nem a SmartRoute ose.";
        else
            cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        SmartRoute sr("Szeged", "Gyor", 2);
        sr.setCheckpoint(0, Checkpoint(85.5, 72));
        sr.setCheckpoint(1, Checkpoint(64.0, 58));
        cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        SmartRoute sr1("Budapest", "Vac", 3);
        sr1.setCheckpoint(0, Checkpoint(15.0, 18));
        sr1.setCheckpoint(1, Checkpoint(17.5, 16));
        sr1.setCheckpoint(2, Checkpoint(12.0, 14));
        SmartRoute sr2("Debrecen", "Nyiregyhaza", 2);
        sr2.setCheckpoint(0, Checkpoint(24.0, 26));
        sr2.setCheckpoint(1, Checkpoint(19.5, 21));
        sr1.print();
        cout << endl;
        sr2.print();
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        SmartRoute sr1("A", "B", 2);
        sr1.setCheckpoint(0, Checkpoint(60.0, 60));
        sr1.setCheckpoint(1, Checkpoint(30.0, 30));
        SmartRoute sr2("C", "D", 3);
        sr2.setCheckpoint(0, Checkpoint(40.0, 40));
        sr2.setCheckpoint(1, Checkpoint(20.0, 30));
        sr2.setCheckpoint(2, Checkpoint(30.0, 20));
        cout << sr1.getAverageSpeed() << endl;
        cout << sr2.getAverageSpeed() << endl;
    }//
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        cout << SmartRoute::getMinimumRecommendedSpeed() << endl;
        SmartRoute::setMinimumRecommendedSpeed(62.5);
        cout << SmartRoute::getMinimumRecommendedSpeed() << endl;
        SmartRoute::setMinimumRecommendedSpeed(55.0);
        cout << SmartRoute::getMinimumRecommendedSpeed() << endl;
    }//
#endif

#ifdef PART6
    {
        TesterGuard tguard("PART6");
        SmartRoute sr1("A", "B", 2); // avg: 72
        sr1.setCheckpoint(0, Checkpoint(54.0, 45));
        sr1.setCheckpoint(1, Checkpoint(18.0, 15));
        SmartRoute sr2("C", "D", 2); // avg: 54
        sr2.setCheckpoint(0, Checkpoint(36.0, 40));
        sr2.setCheckpoint(1, Checkpoint(27.0, 30));
        SmartRoute sr3("E", "F", 2); // avg: 45
        sr3.setCheckpoint(0, Checkpoint(15.0, 20));
        sr3.setCheckpoint(1, Checkpoint(30.0, 40));
        for (double speed : {55.0, 45.0, 70.0})
        {
            SmartRoute::setMinimumRecommendedSpeed(speed);
            cout << "minimum: " << speed << " ->" << flush;
            for (auto sr_addr : {&sr1, &sr2, &sr3})
            {
                const SmartRoute& sr = *sr_addr;
                bool ok = sr.isFastEnough();
                cout << " " << ok << flush;
            }
            cout << endl;
        }
        SmartRoute::setMinimumRecommendedSpeed(55.0);
    }//
#endif

#ifdef PART7
    {
        TesterGuard tguard("PART7");
        if (is_same<SmartRoute,NavigationTools::SmartRoute>::value)
            cout << "Nevter rendben!" << endl;
        else
            cout << "SmartRoute nincs a nevterben!" << endl;
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
