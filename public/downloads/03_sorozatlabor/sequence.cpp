#include "sequence.h"

#include <iostream>
using namespace std;

Sequence::Sequence(int length):
    length(length)
{
}

int Sequence::getLength() const
{
    return length;
}

void Sequence::print() const
{
    cout << length << endl;
    for (int i=0; i<length; i++)
    {
        if (i>0)
            cout << ' ';
        cout << value(i);
    }
    cout << endl;
}

// PART5: ird meg ugy, hogy ugyanazt a formatumot mentse fajlba,
// mint amit a print() a szabvanyos kimenetre kiir.
