#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(string name, Weapon &type):name(name), weapon(type) {}

void HumanA::attack()
{
	cout << this->name << " attacks with their " << this->weapon.getType() << endl;
}

