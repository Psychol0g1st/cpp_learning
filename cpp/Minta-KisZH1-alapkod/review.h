#ifndef REVIEW_H
#define REVIEW_H

#include <string>
using namespace std;

class Review
{
    int stars;
    string comment;
public:
    Review();
    Review(int stars,
           const string& comment);

    int getStars() const;
    const string& getComment() const;

    void print () const;
};

#endif // REVIEW_H
