#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <fstream>
using namespace std;

class Sequence
{
protected:
    int length;
public:
    Sequence(int length);
    virtual ~Sequence()=default;

    int getLength() const;
    virtual int value(int index) const = 0;

    void print() const;
    void saveToFile(const string& path) const;
};

#endif // SEQUENCE_H
