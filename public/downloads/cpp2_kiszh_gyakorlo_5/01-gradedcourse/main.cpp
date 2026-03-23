#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "gradedcourse.h"
#include "course.h"
#include "grade.h"
#endif

struct TesterGuard
{
    string partname;
    TesterGuard (const string& partname);
    ~TesterGuard();
};

namespace AcademicTools {}
using namespace AcademicTools;

int main()
{
    cout << "main() eleje!" << endl;
    cout << fixed << setprecision(2); // sets output format

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        GradedCourse gc("Prog2", 5, 4);
        if (!is_base_of<Course,GradedCourse>::value)
            cout << "Hiba: A Course nem a GradedCourse ose.";
        else
            cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        GradedCourse gc("Analizis", 6, 3);
        gc.setGrade(0, Grade(72,"zh1"));
        gc.setGrade(1, Grade(81,"zh2"));
        gc.setGrade(2, Grade(90,"vizsga"));
        cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        GradedCourse gc1("Prog2", 5, 3);
        gc1.setGrade(0, Grade(78,"zh1"));
        gc1.setGrade(1, Grade(84,"zh2"));
        gc1.setGrade(2, Grade(91,"beadando"));
        GradedCourse gc2("Diszkret", 4, 2);
        gc2.setGrade(0, Grade(56,"teszt"));
        gc2.setGrade(1, Grade(64,"vizsga"));
        gc1.print();
        cout << endl;
        gc2.print();
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        GradedCourse gc1("Adatbazis", 4, 3);
        gc1.setGrade(0, Grade(50,"zh1"));
        gc1.setGrade(1, Grade(70,"zh2"));
        gc1.setGrade(2, Grade(100,"projekt"));
        GradedCourse gc2("Halozatok", 3, 2);
        gc2.setGrade(0, Grade(61,"teszt"));
        gc2.setGrade(1, Grade(61,"vizsga"));
        cout << gc1.getAveragePoints() << endl;
        cout << gc2.getAveragePoints() << endl;
    }//
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        cout << GradedCourse::getPassLimit() << endl;
        GradedCourse::setPassLimit(67.5);
        cout << GradedCourse::getPassLimit() << endl;
        GradedCourse::setPassLimit(60.0);
        cout << GradedCourse::getPassLimit() << endl;
    }//
#endif

#ifdef PART6
    {
        TesterGuard tguard("PART6");
        GradedCourse gc1("A", 5, 2); // avg: 72.50
        gc1.setGrade(0, Grade(70,"..."));
        gc1.setGrade(1, Grade(75,"..."));
        GradedCourse gc2("B", 5, 3); // avg: 60.00
        gc2.setGrade(0, Grade(50,"..."));
        gc2.setGrade(1, Grade(60,"..."));
        gc2.setGrade(2, Grade(70,"..."));
        GradedCourse gc3("C", 5, 4); // avg: 49.00
        gc3.setGrade(0, Grade(40,"..."));
        gc3.setGrade(1, Grade(55,"..."));
        gc3.setGrade(2, Grade(51,"..."));
        gc3.setGrade(3, Grade(50,"..."));
        for (double limit : {60.0, 50.0, 75.0})
        {
            GradedCourse::setPassLimit(limit);
            cout << "minimum: " << limit << " ->" << flush;
            for (auto gc_addr : {&gc1, &gc2, &gc3})
            {
                const GradedCourse& gc = *gc_addr;
                bool passed = gc.isPassed();
                cout << " " << passed << flush;
            }
            cout << endl;
        }
        GradedCourse::setPassLimit(60.0);
    }//
#endif

#ifdef PART7
    {
        TesterGuard tguard("PART7");
        if (is_same<GradedCourse,AcademicTools::GradedCourse>::value)
            cout << "Nevter rendben!" << endl;
        else
            cout << "GradedCourse nincs a nevterben!" << endl;
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
