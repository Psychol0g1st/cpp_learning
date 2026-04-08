#include <iostream>
#include <type_traits>
#include <fstream>
using namespace std;

#include "megoldott_feladatok.h"

#ifdef PART1
#include "cross.h"
#endif

#ifdef PART2
#include "triangle.h"
#endif

#ifdef PART3
#include "mirrorx.h"
#endif

#ifdef PART4
#include "lanterns.h"
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
        if (!is_base_of<Image,Cross>::value)
            cout << "Hiba: Cross nem az Image-bol szarmazik!" << endl;
        Cross c;
        Image& img = c;
        img.print();
    }
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        if (!is_base_of<Image,Triangle>::value)
            cout << "Hiba: Triangle nem az Image-bol szarmazik!" << endl;
        Triangle t1(11,7,5,1,5);
        Triangle t2(9,6,2,0,4);
        Image& img1 = t1;
        Image& img2 = t2;
        img1.print();
        img2.print();
    }
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        if (!is_base_of<Image,MirrorX>::value)
            cout << "Hiba: MirrorX nem az Image-bol szarmazik!" << endl;
        Example1 e1;
        Example2 e2;
        MirrorX m1(&e1);
        MirrorX m2(&e2);
        m1.print();
        m2.print();
    }
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        if (!is_base_of<Image,Lanterns>::value)
            cout << "Hiba: Lanterns nem az Image-bol szarmazik!" << endl;
        Lanterns l1(11,7);
        l1.addLantern(2,2,1);
        l1.addLantern(8,4,2);
        Lanterns l2(9,6);
        l2.addLantern(1,1,2);
        l2.addLantern(7,3,1);
        l1.print();
        l2.print();
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
