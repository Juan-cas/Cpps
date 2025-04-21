#include "HumanB.hpp"

HumanB::HumanB(string name) : name(name), weapon(0) {}

void HumanB::setWeapon(Weapon &type)
{
	this->weapon = &type;
}

void HumanB::attack()
{
	cout << this->name << " attacks with their " << this->weapon->getType() << endl;
}
