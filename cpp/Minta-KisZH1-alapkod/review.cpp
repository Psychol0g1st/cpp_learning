#include "review.h"

#include <iostream>
using namespace std;

Review::Review():
    stars(0),
    comment("<MISSING REVIEW>")
{
}

Review::Review(int stars, const string& comment):
    stars(stars),
    comment(comment)
{
}

int Review::getStars() const
{
    return stars;
}

const string& Review::getComment() const
{
    return comment;
}

void Review::print() const
{
    cout << "[";
    for (int i=1;i<=5;i++)
        cout << (stars>=i ? '*' : ' ');
    cout << "] " << comment << endl;
}
