#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
    string name;
    int credits;
public:
    Course(const string& name,
           int credits);

    string getName() const;
    int getCredits() const;

    void print() const;
};

#endif // COURSE_H
