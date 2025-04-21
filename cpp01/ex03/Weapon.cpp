#include "Weapon.hpp"

Weapon::Weapon(string weapon)
{
	this->type = weapon;
}

void Weapon::setType(string Weapon)
{
	this->type = Weapon;
}

string Weapon::getType()
{
	return this->type;
}

