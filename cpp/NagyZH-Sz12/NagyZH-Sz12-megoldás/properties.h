#pragma once
#include <string>
#include "dragon.h"
using namespace std;
//ososztaly
class Properties
{
public:
	Properties(string ID, int price);
	virtual ~Properties() = default;
	string getID() const;
	int getPrice() const;
	virtual void print() = 0;
	virtual void attack(Dragon& dragon) = 0;
private:
	string ID;
	int price;
};
