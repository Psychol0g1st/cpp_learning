#ifndef MATCHRESULT_H
#define MATCHRESULT_H

class MatchResult
{
    int scored;
    int conceded;
public:
    MatchResult();
    MatchResult(int scored,
                int conceded);

    int getScored() const;
    int getConceded() const;

    void print() const;
};

#endif // MATCHRESULT_H
