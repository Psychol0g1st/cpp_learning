#include <iostream>
#include <type_traits>
#include <fstream>
using namespace std;

#include "megoldott_feladatok.h"

#ifdef PART1
#include "frame.h"
#endif

#ifdef PART2
#include "stairs.h"
#endif

#ifdef PART3
#include "overlay.h"
#endif

#ifdef PART4
#include "labels.h"
#endif

#include "canvas.h"
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
        Canvas& c = e1;
        c.print();
    }
    {
        cout << "Example2 teszt:" << endl;
        Example2 e2;
        Canvas& c = e2;
        c.print();
    }

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        if (!is_base_of<Canvas,Frame>::value)
            cout << "Hiba: Frame nem a Canvas-bol szarmazik!" << endl;
        Frame f;
        Canvas& c = f;
        c.print();
    }
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        if (!is_base_of<Canvas,Stairs>::value)
            cout << "Hiba: Stairs nem a Canvas-bol szarmazik!" << endl;
        Stairs s1(8,5);
        Stairs s2(10,6);
        Canvas& a = s1;
        Canvas& b = s2;
        a.print();
        b.print();
    }
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        if (!is_base_of<Canvas,Overlay>::value)
            cout << "Hiba: Overlay nem a Canvas-bol szarmazik!" << endl;
        Example1 e1;
        Example2 e2;
        Overlay o1(&e1,&e2);
        Overlay o2(&e2,&e1);
        o1.print();
        o2.print();
    }
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        if (!is_base_of<Canvas,Labels>::value)
            cout << "Hiba: Labels nem a Canvas-bol szarmazik!" << endl;
        Labels l1(10,5);
        l1.addLabel(1,1,'A');
        l1.addLabel(4,2,'B');
        l1.addLabel(8,3,'C');

        Labels l2(12,6);
        l2.addLabel(0,0,'H');
        l2.addLabel(1,0,'I');
        l2.addLabel(10,5,'!');
        l2.addLabel(5,2,'*');

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
