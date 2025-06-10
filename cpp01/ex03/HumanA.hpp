#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
public:
  HumanA(std::string name, Weapon &type);
  void setWeapon(Weapon &type);
  void attack();

private:
  std::string name;
  Weapon &weapon;
};

#endif // HUMANA_HPP
