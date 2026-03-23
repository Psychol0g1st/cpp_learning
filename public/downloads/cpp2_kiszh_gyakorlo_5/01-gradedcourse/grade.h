#ifndef GRADE_H
#define GRADE_H

#include <string>
using namespace std;

class Grade
{
    int points;
    string note;
public:
    Grade();
    Grade(int points,
          const string& note);

    int getPoints() const;
    const string& getNote() const;

    void print() const;
};

#endif // GRADE_H
