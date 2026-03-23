#include "matchresult.h"

#include <iostream>
using namespace std;

MatchResult::MatchResult():
    scored(0),
    conceded(0)
{
}

MatchResult::MatchResult(int scored,
                         int conceded):
    scored(scored),
    conceded(conceded)
{
}

int MatchResult::getScored() const
{
    return scored;
}

int MatchResult::getConceded() const
{
    return conceded;
}

void MatchResult::print() const
{
    cout << scored << ":" << conceded << endl;
}
