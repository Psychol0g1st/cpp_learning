#include "btoy.h"

BToy::BToy(const string &id,
           const string &name,
           int price,
           int quantity,
           int age):
    BProduct(id,name,price,quantity),
    age(age)
{
}

int BToy::getAge() const
{
    return age;
}

string BToy::type() const
{
    return "toy";
}

void BToy::print(ostream &os) const
{
    BProduct::print(os);
    os << ", age: " << age;
}
