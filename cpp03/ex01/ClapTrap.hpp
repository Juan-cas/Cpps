#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

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
  virtual std::string get_name(void) const;
  virtual int get_hp(void) const;
  virtual int get_ep(void) const;
  virtual int get_dmg(void) const;

  // setters:
  virtual void set_name(std::string name);
  virtual void set_hp(int hp);
  virtual void set_ep(int ep);
  virtual void set_dmg(int dmg);

  // foos
  virtual void attack(const std::string &target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);
  virtual void use_energy(void);
};

#endif
