#ifndef TAVERN_H
#define TAVERN_H
#include "properties.h"
#include <vector>
using namespace std;

//kezelo osztaly
class Tavern
{
public:
	Tavern();
	~Tavern();
	void loadAll(const string& fajlnev1, const string& fajlnev2, const string& fajlnev3);
	void printAll() const;
	Properties* getByID(const string& id) const;
private:
	vector<Properties*> karakters;
};

//gyerekosztalyok
class Archer : public Properties
{
public:
	Archer(string ID, int price, int agility);
	~Archer();
	int getAgility() const;
	virtual void print() override;
	virtual void attack(Dragon& dragon) override;
private:
	int agility;
};


class Knight : public Properties
{
public:
	Knight(string ID, int price, int strength);
	~Knight();
	int getStrength() const;
	virtual void print() override;
	virtual void attack(Dragon& dragon) override;
private:
	int strength;
};


class Mage : public Properties
{
public:
	Mage(string ID, int price, double magic);
	~Mage();
	double getMagic() const;
	virtual void print() override;
	virtual void attack(Dragon& dragon) override;
private:
	double magic;
};
#endif // TAVERN_H
