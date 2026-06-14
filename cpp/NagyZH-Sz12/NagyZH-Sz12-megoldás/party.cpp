#include "party.h"
#include "tavern.h"
#include <string>
#include <fstream>
#include <iostream>
Party::Party(const string& fajlnev, const Tavern& tavern) : tavern(tavern)
{
	loadParties(fajlnev);
}

Party::~Party()
{
}

void Party::loadParties(const string& fajlnev)
{
	ifstream file(fajlnev);

	if (file.is_open())
	{
		string id;
		while (file >> id)
		{
			Properties* mutato = tavern.getByID(id);
			IDPointers.push_back(mutato);
		}
	}
}

void Party::printAll() const
{
	for (unsigned int i = 0; i < IDPointers.size(); i++)
	{
		IDPointers.at(i)->print();
	}
}

int Party::getTotalCost() const
{
	int osszeg = 0;
	for (unsigned int i = 0; i < IDPointers.size(); i++)
	{
		osszeg += IDPointers[i]->getPrice();
	}
	return osszeg;
}

void Party::raid(Dragon& dragon)
{

	while (dragon.getHP() > 0 && IDPointers.size() > 0)
	{
		for (unsigned int i = 0; i < IDPointers.size(); i++)
		{
			IDPointers.at(i)->attack(dragon);
			cout << IDPointers.at(i)->getID() << " tamad! Sarkany HP: " << dragon.getHP() << endl;
			if (dragon.getHP() <= 0)
			{
				cout << "GYOZELEM!" << endl;
				return;
			}
			
		}
		cout << "*** Sarkany felfalja: " << IDPointers.at(0)->getID() << endl;
		IDPointers.erase(IDPointers.begin());
	}
	cout << "VERESEG!" << endl;
}


