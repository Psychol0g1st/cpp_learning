#ifndef TEAM_H
#define TEAM_H

#include <string>
using namespace std;

class Team
{
    string name;
    string city;
public:
    Team(const string& name,
         const string& city);

    string getName() const;
    string getCity() const;

    void print() const;
};

#endif // TEAM_H
