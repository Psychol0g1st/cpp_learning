#include <iostream>
using namespace std;

// sajat include-ok (osztalyok szabadon atnevezhetok)
#include "tavern.h"
#include "party.h"

// #define PART1 // Tavern, beolvas JSON fajlokbol
// #define PART2 // Tavern, printAll()
// #define PART3 // Party, beolvasas szovegfajlbol
// #define PART4 // Party, printAll()
// #define PART5 // Party, getTotalCost()
// #define PART6 // Party, raid()

int main()
{
    cout << "main() eleje!" << endl << endl;

#ifdef PART1
    cout << "--- Tavern, beolvas JSON fajlokbol" << endl;
    Tavern tavern;
    tavern.loadAll("in-knights.json",
                   "in-rangers.json",
                   "in-mages.json");
    cout << "Megtortent." << endl << endl;
#endif

#ifdef PART2
    cout << "--- Tavern, printAll()" << endl;
    tavern.printAll();
    cout << endl;
#endif

#ifdef PART3
    cout << "--- Party, beolvasas szovegfajlbol" << endl;
    Party party1("in-party-1.txt", tavern);
    Party party2("in-party-2.txt", tavern);
    Party party3("in-party-3.txt", tavern);
    cout << "Megtortent." << endl << endl;
#endif

#ifdef PART4
    cout << "--- Party, printAll()" << endl;
    cout << endl << "Party1:" << endl;
    party1.printAll();
    cout << endl << "Party2:" << endl;
    party2.printAll();
    cout << endl << "Party3:" << endl;
    party3.printAll();
    cout << endl;
#endif

#ifdef PART5
    cout << "--- Party, getTotalCost()" << endl;
    cout << "Party1 zsoldja: " << party1.getTotalCost() << endl;
    cout << "Party2 zsoldja: " << party2.getTotalCost() << endl;
    cout << "Party3 zsoldja: " << party3.getTotalCost() << endl;
    cout << endl;
#endif

#ifdef PART6
    cout << "--- Party, raid()" << endl;
    {
        cout << endl << "Party1 vs Dragon1:" << endl;
        Dragon dragon1("Dragon1",1500,30);
        party1.raid(dragon1);
    }
    {
        cout << endl << "Party2 vs Dragon2:" << endl;
        Dragon dragon2("Dragon2",500,200);
        party2.raid(dragon2);
    }
    {
        cout << endl << "Party3 vs Dragon3:" << endl;
        Dragon dragon3("Dragon3",1700,50);
        party3.raid(dragon3);
    }
    cout << endl;
#endif

    cout << "main() vege!" << endl;
    return 0;
}
