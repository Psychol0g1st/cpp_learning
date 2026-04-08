#include <iostream>
#include <type_traits>
#include <fstream>
using namespace std;

#include "megoldott_feladatok.h"

#ifdef PART1
#include "arithmetic.h"
#endif

#ifdef PART2
#include "zigzag.h"
#endif

#ifdef PART3
#include "reversed.h"
#endif

#ifdef PART4
#include "marked.h"
#endif

#include "sequence.h"
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
        Sequence& s = e1;
        s.print();
    }
    {
        cout << "Example2 teszt:" << endl;
        Example2 e2;
        Sequence& s = e2;
        s.print();
    }

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        if (!is_base_of<Sequence,ArithmeticSequence>::value)
            cout << "Hiba: ArithmeticSequence nem a Sequence-bol szarmazik!" << endl;
        ArithmeticSequence s1(3,4,6);
        ArithmeticSequence s2(-2,3,5);
        Sequence& a = s1;
        Sequence& b = s2;
        a.print();
        b.print();
    }
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        if (!is_base_of<Sequence,ZigZagSequence>::value)
            cout << "Hiba: ZigZagSequence nem a Sequence-bol szarmazik!" << endl;
        ZigZagSequence s1(2,5,9);
        ZigZagSequence s2(-1,1,7);
        Sequence& a = s1;
        Sequence& b = s2;
        a.print();
        b.print();
    }
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        if (!is_base_of<Sequence,ReverseSequence>::value)
            cout << "Hiba: ReverseSequence nem a Sequence-bol szarmazik!" << endl;
        Example1 e1;
        Example2 e2;
        ReverseSequence r1(&e1);
        ReverseSequence r2(&e2);
        r1.print();
        r2.print();
    }
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        if (!is_base_of<Sequence,MarkedSequence>::value)
            cout << "Hiba: MarkedSequence nem a Sequence-bol szarmazik!" << endl;
        Example1 e1;
        MarkedSequence m1(&e1);
        m1.mark(1,100);
        m1.mark(4,-5);

        ArithmeticSequence a1(10,10,6);
        MarkedSequence m2(&a1);
        m2.mark(0,7);
        m2.mark(5,99);
        m2.mark(2,42);

        m1.print();
        m2.print();
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
