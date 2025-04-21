#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
	explicit HumanB(string name);
	void setWeapon(Weapon &weapon);
	void attack();
private:
	string name;
	Weapon *weapon;
};

#endif
