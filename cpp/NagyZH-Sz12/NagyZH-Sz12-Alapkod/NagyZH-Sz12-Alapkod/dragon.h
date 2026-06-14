#ifndef DRAGON_H
#define DRAGON_H

//
// A "sarkany" osztaly forraskodja nem modosithato.
//

#include <string>
using namespace std;

class Dragon
{
    const string name;
    int HP; // a sarkany eletereje
    const int MaxHP;
    int armor; // a sarkany pancelja
public:
    Dragon(const string& name,
           int maxHP,
           int armor);

    const string& getName() const;
    int getHP() const;
    void setHP(int newHP); // itt lehet modositani a sarkany eleterejet
    int getArmor() const;
};

#endif // DRAGON_H
