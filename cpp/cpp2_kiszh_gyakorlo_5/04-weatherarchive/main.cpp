#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "weatherarchive.h"
#include "station.h"
#include "measurement.h"
#endif

struct TesterGuard
{
    string partname;
    TesterGuard (const string& partname);
    ~TesterGuard();
};

namespace WeatherTools {}
using namespace WeatherTools;

int main()
{
    cout << "main() eleje!" << endl;
    cout << fixed << setprecision(2); // sets output format

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        WeatherArchive wa("Szeged", "SZGD", 3);
        if (!is_base_of<Station,WeatherArchive>::value)
            cout << "Hiba: A Station nem a WeatherArchive ose.";
        else
            cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        WeatherArchive wa("Pecs", "PECS", 2);
        wa.setMeasurement(0, Measurement(24.5,"08:00"));
        wa.setMeasurement(1, Measurement(29.0,"14:00"));
        cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        WeatherArchive wa1("Debrecen", "DEBR", 3);
        wa1.setMeasurement(0, Measurement(21.5,"06:00"));
        wa1.setMeasurement(1, Measurement(27.0,"12:00"));
        wa1.setMeasurement(2, Measurement(24.0,"18:00"));
        WeatherArchive wa2("Gyor", "GYOR", 2);
        wa2.setMeasurement(0, Measurement(18.0,"07:00"));
        wa2.setMeasurement(1, Measurement(20.5,"15:00"));
        wa1.print();
        cout << endl;
        wa2.print();
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        WeatherArchive wa1("A", "AA", 3);
        wa1.setMeasurement(0, Measurement(25.0,"m1"));
        wa1.setMeasurement(1, Measurement(30.0,"m2"));
        wa1.setMeasurement(2, Measurement(20.0,"m3"));
        WeatherArchive wa2("B", "BB", 2);
        wa2.setMeasurement(0, Measurement(28.0,"m1"));
        wa2.setMeasurement(1, Measurement(29.5,"m2"));
        cout << wa1.getAverageTemperature() << endl;
        cout << wa2.getAverageTemperature() << endl;
    }//
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        cout << WeatherArchive::getHeatAlertLevel() << endl;
        WeatherArchive::setHeatAlertLevel(30.0);
        cout << WeatherArchive::getHeatAlertLevel() << endl;
        WeatherArchive::setHeatAlertLevel(27.5);
        cout << WeatherArchive::getHeatAlertLevel() << endl;
    }//
#endif

#ifdef PART6
    {
        TesterGuard tguard("PART6");
        WeatherArchive wa1("A", "AA", 2); // avg: 30.00
        wa1.setMeasurement(0, Measurement(31.0,"..."));
        wa1.setMeasurement(1, Measurement(29.0,"..."));
        WeatherArchive wa2("B", "BB", 3); // avg: 27.00
        wa2.setMeasurement(0, Measurement(26.0,"..."));
        wa2.setMeasurement(1, Measurement(27.0,"..."));
        wa2.setMeasurement(2, Measurement(28.0,"..."));
        WeatherArchive wa3("C", "CC", 4); // avg: 24.50
        wa3.setMeasurement(0, Measurement(24.0,"..."));
        wa3.setMeasurement(1, Measurement(25.0,"..."));
        wa3.setMeasurement(2, Measurement(23.0,"..."));
        wa3.setMeasurement(3, Measurement(26.0,"..."));
        for (double level : {27.5, 24.5, 30.5})
        {
            WeatherArchive::setHeatAlertLevel(level);
            cout << "minimum: " << level << " ->" << flush;
            for (auto wa_addr : {&wa1, &wa2, &wa3})
            {
                const WeatherArchive& wa = *wa_addr;
                bool ok = wa.isHeatAlert();
                cout << " " << ok << flush;
            }
            cout << endl;
        }
        WeatherArchive::setHeatAlertLevel(27.5);
    }//
#endif

#ifdef PART7
    {
        TesterGuard tguard("PART7");
        if (is_same<WeatherArchive,WeatherTools::WeatherArchive>::value)
            cout << "Nevter rendben!" << endl;
        else
            cout << "WeatherArchive nincs a nevterben!" << endl;
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
