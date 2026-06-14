#include "tavern.h"
#include <iostream>
#include <fstream>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

Archer::Archer(string ID, int price, int agility) : Properties(ID, price), agility(agility)
{
}

Archer::~Archer()
{
}

int Archer::getAgility() const
{
	return agility;
}

void Archer::print()
{	//[Ranger R2, price: 115, agility: 35]
	cout << "[Ranger " << getID() << ", price: " << getPrice() << ", agility: " << getAgility() << "]" << endl;
}

void Archer::attack(Dragon& dragon)
{
	int sebzes = getAgility();
	dragon.setHP(dragon.getHP() - sebzes);
}

Knight::Knight(string ID, int price, int strength) : Properties(ID, price), strength(strength)
{
}

Knight::~Knight()
{
}

int Knight::getStrength() const
{
	return strength;
}

void Knight::print()
{//[Knight K1, price: 120, strength: 80]
	cout << "[Knight " << getID() << ", price: " << getPrice() << ", strength: " << getStrength() << "]" << endl;
}

void Knight::attack(Dragon& dragon)
{
	int sebzes = 0;
	sebzes = getStrength() - dragon.getArmor();
	if (sebzes < 1)
	{
		sebzes = 1;
	}
	dragon.setHP(dragon.getHP() - sebzes);
}

Mage::Mage(string ID, int price, double magic) : Properties(ID, price), magic(magic)
{
}

Mage::~Mage()
{
}

double Mage::getMagic() const
{
	return magic;
}

void Mage::print()
{//[Mage M1, price: 200, magic: 0.01]
	cout << "[Mage " << getID() << ", price: " << getPrice() << ", magic " << getMagic() << "]" << endl;
}

void Mage::attack(Dragon& dragon)
{
	dragon.setHP(dragon.getHP() * (1 - getMagic()));
}

Tavern::Tavern()
{
}

Tavern::~Tavern()
{
}

void Tavern::loadAll(const string& fajlnev1, const string& fajlnev2, const string& fajlnev3)
{
	vector<string> fajlnevek = { fajlnev1, fajlnev2, fajlnev3 };
	for (const string& aktualisFajl : fajlnevek)
	{
		ifstream file(aktualisFajl);

		if (file.is_open())
		{
			json root = json::parse(file);
			if (aktualisFajl == "in-knights.json")
			{
				for (unsigned int i = 0; i < root.size(); i++)
				{
					Knight* knight = new Knight(root[i]["Id"], root[i]["Price"], root[i]["Strength"]);
					karakters.push_back(knight);
				}
			}
			if (aktualisFajl == "in-rangers.json")
			{
				for (unsigned int i = 0; i < root.size(); i++)
				{
					Archer* archer = new Archer(root[i]["Id"], root[i]["Price"], root[i]["Agility"]);
					karakters.push_back(archer);
				}
			}
			if (aktualisFajl == "in-mages.json")
			{
				for (unsigned int i = 0; i < root.size(); i++)
				{
					Mage* mage = new Mage(root[i]["Id"], root[i]["Price"], root[i]["Magic"]);
					karakters.push_back(mage);
				}
			}
		}

	}

}

void Tavern::printAll() const
{
	for (unsigned int i = 0; i < karakters.size(); i++)
	{
		karakters.at(i)->print();
	}
}

Properties* Tavern::getByID(const string& id) const
{
	for (unsigned int i = 0; i < karakters.size(); i++)
	{
		if (karakters.at(i)->getID() == id)
		{
			return karakters.at(i);
		}
	}
	return nullptr;
}
