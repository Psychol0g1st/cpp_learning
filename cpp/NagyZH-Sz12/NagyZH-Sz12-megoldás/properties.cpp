#include "properties.h"
#include <string>

using namespace std;

Properties::Properties(string ID, int price) : ID(ID), price(price)
{
}


string Properties::getID() const
{
	return ID;
}

int Properties::getPrice() const
{
	return price;
}

void Properties::print()
{
}
