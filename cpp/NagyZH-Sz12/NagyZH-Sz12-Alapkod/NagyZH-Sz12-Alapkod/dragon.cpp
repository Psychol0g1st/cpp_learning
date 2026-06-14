#include "dragon.h"

//
// A "sarkany" osztaly forraskodja nem modosithato.
//

Dragon::Dragon(const string &name,
               int maxHP,
               int armor):
    name(name),
    HP(maxHP),
    MaxHP(maxHP),
    armor(armor)
{
}

const string &Dragon::getName() const
{
    return name;
}

int Dragon::getHP() const
{
    return HP;
}

void Dragon::setHP(int newHP)
{
    HP = newHP;
}

int Dragon::getArmor() const
{
    return armor;
}
