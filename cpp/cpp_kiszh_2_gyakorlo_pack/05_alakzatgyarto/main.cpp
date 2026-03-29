#include <iostream>
#include <type_traits>
#include <fstream>
using namespace std;

#include "megoldott_feladatok.h"

#ifdef PART1
#include "verticalstripes.h"
#endif

#ifdef PART2
#include "hourglass.h"
#endif

#ifdef PART3
#include "shifted.h"
#endif

#ifdef PART4
#include "targets.h"
#endif

#include "image.h"
#include "example.h"

struct TesterGuard
{
    string partname;
    TesterGuard(const string& partname);
    ~TesterGuard();
};

namespace ToolsForRating {}
using namespace ToolsForRating;

int main()
{
    cout << "main() eleje!" << endl;

    {
        cout << "Example1 teszt:" << endl;
        Example1 e1;
        Image& img = e1;
        img.print();
    }
    {
        cout << "Example2 teszt:" << endl;
        Example2 e2;
        Image& img = e2;
        img.print();
    }

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        if (!is_base_of<Image,VerticalStripes>::value)
            cout << "Hiba: VerticalStripes nem az Image-bol szarmazik!" << endl;
        VerticalStripes s1(9,5,2);
        VerticalStripes s2(10,4,3);
        s1.print();
        s2.print();
    }
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        if (!is_base_of<Image,Hourglass>::value)
            cout << "Hiba: Hourglass nem az Image-bol szarmazik!" << endl;
        Hourglass h1(9,5);
        Hourglass h2(11,7);
        h1.print();
        h2.print();
    }
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        if (!is_base_of<Image,Shifted>::value)
            cout << "Hiba: Shifted nem az Image-bol szarmazik!" << endl;
        Example1 e1;
        Example2 e2;
        Shifted s1(&e1,2,1);
        Shifted s2(&e2,-1,2);
        s1.print();
        s2.print();
    }
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        if (!is_base_of<Image,Targets>::value)
            cout << "Hiba: Targets nem az Image-bol szarmazik!" << endl;
        Targets t1(11,7);
        t1.addTarget(3,3,2);
        t1.addTarget(8,2,1);

        Targets t2(9,6);
        t2.addTarget(1,1,1);
        t2.addTarget(6,4,2);

        t1.print();
        t2.print();
    }
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        Example1 e1;
        Example2 e2;
        e1.saveToFile("example1.txt");
        e2.saveToFile("example2.txt");
        for (const char* path : {"example1.txt","example2.txt"})
        {
            cout << path << " tartalma:" << endl;
            ifstream in(path);
            if (in.is_open())
                cout << in.rdbuf() << endl;
            else
                cout << "Hiba: nem sikerult megnyitni!" << endl;
        }
    }
#endif

    cout << "main() vege!" << endl;
    return 0;
}

TesterGuard::TesterGuard(const string& p):
    partname(p)
{
    cout << endl << "----START OF " << partname << "----" << endl << endl;
}

TesterGuard::~TesterGuard()
{
    cout << endl << "----END OF " << partname << "----" << endl << endl;
}
