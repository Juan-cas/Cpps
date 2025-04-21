#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap constructor called" << std::endl;
  this->Hitpoints = FragTrap::Hitpoints;
  this->Attackdamage = FragTrap::Attackdamage;
  this->Energypoints = ScavTrap::Energypoints;
}

DiamondTrap::DiamondTrap(const std::string& name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), Name(name) {
  std::cout << "DiamondTrap " << Name << "> Status: Created" << std::endl;
  this->set_hp(FragTrap::get_hp());
  this->Energypoints = ScavTrap::Energypoints;
  this->Attackdamage = FragTrap::Attackdamage;

}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap's destructor has been called" << std::endl;
}

