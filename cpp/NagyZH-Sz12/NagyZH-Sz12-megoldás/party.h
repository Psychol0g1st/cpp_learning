#ifndef PARTY_H
#define PARTY_H
#include "tavern.h"
#include <string>
#include <vector>

using namespace std;

class Party
{
public:
	Party(const string& fajlnev, const Tavern& tavern);
	~Party();
	void loadParties(const string& fajlnev);
	void printAll() const;
	int getTotalCost() const;
	void raid(Dragon& dragon);
private:
	vector<Properties*> IDPointers;
	Tavern tavern;
};

#endif // PARTY_H
