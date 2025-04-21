#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

using namespace std;

class Weapon {
	public:
	explicit Weapon(string weapon);
	string getType();
	void setType(string Weapon);
private:
string type;
};

#endif //WEAPON_HPP
