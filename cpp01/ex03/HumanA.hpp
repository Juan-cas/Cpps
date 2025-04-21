#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA(string name, Weapon &type);
	void setWeapon(Weapon &type);
	void attack();
private:
	string name;
	Weapon &weapon;
};

#endif //HUMANA_HPP
