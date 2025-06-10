#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
  std::string _Name;
  int _Hitpoints;
  int _Energypoints;
  int _Attackdamage;

public:
  // constructors:
  ClapTrap();
  ClapTrap(const std::string input);
  ClapTrap(const ClapTrap &robot);
  virtual ~ClapTrap();

  // overloads:
  ClapTrap &operator=(const ClapTrap &tmp);

  // getters:
  std::string get_name(void);
  int get_hp(void);
  int get_ep(void);
  int get_dmg(void);

  // setters:
  void set_name(std::string name);
  void set_hp(int hp);
  void set_ep(int ep);
  void set_dmg(int dmg);

  // foos
  virtual void attack(const std::string &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  virtual void use_energy(void);
};

#endif
