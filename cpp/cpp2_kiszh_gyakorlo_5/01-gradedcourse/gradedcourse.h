#ifndef GRADECOURSE_H
#define GRADECOURSE_H

#include <string>
#include "course.h"
using namespace std;

class GradeCourse: public Course
{
public:
    GradeCourse(const string& name, int credits, int reviewsCount);
d
};

#endif // GRADECOURSE_H
