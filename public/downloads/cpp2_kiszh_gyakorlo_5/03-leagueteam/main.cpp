#include <iostream>
#include <string>
#include <iomanip>
#include <type_traits>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "leagueteam.h"
#include "team.h"
#include "matchresult.h"
#endif

struct TesterGuard
{
    string partname;
    TesterGuard (const string& partname);
    ~TesterGuard();
};

namespace LeagueStats {}
using namespace LeagueStats;

int main()
{
    cout << "main() eleje!" << endl;
    cout << fixed << setprecision(2); // sets output format

#ifdef PART1
    {
        TesterGuard tguard("PART1");
        LeagueTeam lt("Rockets", "Szeged", 4);
        if (!is_base_of<Team,LeagueTeam>::value)
            cout << "Hiba: A Team nem a LeagueTeam ose.";
        else
            cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        LeagueTeam lt("Falcons", "Gyor", 3);
        lt.setResult(0, MatchResult(2,1));
        lt.setResult(1, MatchResult(0,0));
        lt.setResult(2, MatchResult(1,3));
        cout << "Latszolag OK." << endl;
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        LeagueTeam lt1("Lions", "Budapest", 4);
        lt1.setResult(0, MatchResult(2,0));
        lt1.setResult(1, MatchResult(1,1));
        lt1.setResult(2, MatchResult(3,2));
        lt1.setResult(3, MatchResult(0,1));
        LeagueTeam lt2("Waves", "Pecs", 3);
        lt2.setResult(0, MatchResult(0,0));
        lt2.setResult(1, MatchResult(4,2));
        lt2.setResult(2, MatchResult(1,2));
        lt1.print();
        cout << endl;
        lt2.print();
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        LeagueTeam lt1("A", "X", 4);
        lt1.setResult(0, MatchResult(2,0));
        lt1.setResult(1, MatchResult(1,1));
        lt1.setResult(2, MatchResult(3,2));
        lt1.setResult(3, MatchResult(0,1));
        LeagueTeam lt2("B", "Y", 3);
        lt2.setResult(0, MatchResult(0,0));
        lt2.setResult(1, MatchResult(1,1));
        lt2.setResult(2, MatchResult(2,3));
        cout << lt1.getAveragePoints() << endl;
        cout << lt2.getAveragePoints() << endl;
    }//
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        cout << LeagueTeam::getPlayoffLevel() << endl;
        LeagueTeam::setPlayoffLevel(2.10);
        cout << LeagueTeam::getPlayoffLevel() << endl;
        LeagueTeam::setPlayoffLevel(1.80);
        cout << LeagueTeam::getPlayoffLevel() << endl;
    }//
#endif

#ifdef PART6
    {
        TesterGuard tguard("PART6");
        LeagueTeam lt1("A", "X", 4); // avg: 2.50
        lt1.setResult(0, MatchResult(1,0));
        lt1.setResult(1, MatchResult(2,1));
        lt1.setResult(2, MatchResult(0,0));
        lt1.setResult(3, MatchResult(3,2));
        LeagueTeam lt2("B", "Y", 4); // avg: 1.50
        lt2.setResult(0, MatchResult(1,1));
        lt2.setResult(1, MatchResult(2,3));
        lt2.setResult(2, MatchResult(0,0));
        lt2.setResult(3, MatchResult(4,1));
        LeagueTeam lt3("C", "Z", 4); // avg: 0.75
        lt3.setResult(0, MatchResult(0,1));
        lt3.setResult(1, MatchResult(0,0));
        lt3.setResult(2, MatchResult(1,2));
        lt3.setResult(3, MatchResult(2,4));
        for (double level : {1.8, 1.0, 2.6})
        {
            LeagueTeam::setPlayoffLevel(level);
            cout << "minimum: " << level << " ->" << flush;
            for (auto lt_addr : {&lt1, &lt2, &lt3})
            {
                const LeagueTeam& lt = *lt_addr;
                bool ok = lt.isPlayoffReady();
                cout << " " << ok << flush;
            }
            cout << endl;
        }
        LeagueTeam::setPlayoffLevel(1.8);
    }//
#endif

#ifdef PART7
    {
        TesterGuard tguard("PART7");
        if (is_same<LeagueTeam,LeagueStats::LeagueTeam>::value)
            cout << "Nevter rendben!" << endl;
        else
            cout << "LeagueTeam nincs a nevterben!" << endl;
    }//
#endif

    cout << "main() vege!" << endl;
    return 0;
}

TesterGuard::TesterGuard(const string &p):
    partname(p)
{
    cout << endl << "----START OF " << partname << "----" << endl << endl;
}

TesterGuard::~TesterGuard()
{
    cout << endl << "----END OF " << partname << "----" << endl << endl;
}
