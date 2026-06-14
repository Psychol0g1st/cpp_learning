#include "bproduct.h"

BProduct::BProduct(const string &id,
                   const string &name,
                   int price,
                   int quantity):
    id(id),
    name(name),
    price(price),
    quantity(quantity)
{
}

const string &BProduct::getId() const
{
    return id;
}

int BProduct::getPrice() const
{
    return price;
}

void BProduct::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int BProduct::getQuantity() const
{
    return quantity;
}

const string &BProduct::getName() const
{
    return name;
}

void BProduct::print(ostream &os) const
{
    os << quantity << " x ";
    os << "#" << id << "(";
    os << type() << "): ";
    os << name << ", ";
    os << price << " Ft";
}

ostream& operator<< (ostream& os, const BProduct& p)
{
    p.print(os);
    return os;
}
