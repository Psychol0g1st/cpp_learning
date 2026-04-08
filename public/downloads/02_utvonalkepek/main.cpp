#include <iostream>
#include <type_traits>
#include <fstream>
using namespace std;

#include "megoldott_feladatok.h"

#ifdef PART1
#include "border.h"
#endif

#ifdef PART2
#include "diamond.h"
#endif

#ifdef PART3
#include "negative.h"
#endif

#ifdef PART4
#include "pathimage.h"
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
        if (!is_base_of<Image,Border>::value)
            cout << "Hiba: Border nem az Image-bol szarmazik!" << endl;
        Border b;
        Image& img = b;
        img.print();
    }
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        if (!is_base_of<Image,Diamond>::value)
            cout << "Hiba: Diamond nem az Image-bol szarmazik!" << endl;
        Diamond d1(11,7,5,3,3);
        Diamond d2(9,6,2,2,2);
        Image& img1 = d1;
        Image& img2 = d2;
        img1.print();
        img2.print();
    }
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        if (!is_base_of<Image,Negative>::value)
            cout << "Hiba: Negative nem az Image-bol szarmazik!" << endl;
        Example1 e1;
        Example2 e2;
        Negative n1(&e1);
        Negative n2(&e2);
        n1.print();
        n2.print();
    }
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        if (!is_base_of<Image,PathImage>::value)
            cout << "Hiba: PathImage nem az Image-bol szarmazik!" << endl;
        PathImage p1(11,7);
        p1.addPoint(1,1);
        p1.addPoint(6,1);
        p1.addPoint(6,4);
        p1.addPoint(3,4);

        PathImage p2(10,6);
        p2.addPoint(0,5);
        p2.addPoint(0,2);
        p2.addPoint(4,2);
        p2.addPoint(4,0);

        p1.print();
        p2.print();
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
