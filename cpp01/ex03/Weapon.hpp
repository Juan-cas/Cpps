#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public:
  Weapon();
  Weapon(std::string weapon);
  ~Weapon();
  std::string getType();
  void setType(std::string Weapon);

private:
  std::string _Type;
};

#endif // WEAPON_HPP
