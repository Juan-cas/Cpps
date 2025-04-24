#include "ClapTrap.hpp"
#include <iostream>

// getters

std::string ClapTrap::get_name(void) { return this->_Name; }
int ClapTrap::get_hp(void) { return this->_Hitpoints; }
int ClapTrap::get_ep(void) { return this->_Energypoints; }
int ClapTrap::get_dmg(void) { return this->_Attackdamage; }

// setters

void ClapTrap::set_hp(int hp) { this->_Hitpoints = hp; }
void ClapTrap::set_ep(int ep) { this->_Energypoints = ep; }
void ClapTrap::set_dmg(int dmg) { this->_Attackdamage = dmg; }
void ClapTrap::set_name(std::string name) { this->_Name = name;}

// constructor & destructor

ClapTrap::ClapTrap() {
  std::cout << "ClapTrap constructor called" << std::endl;
  this->set_hp(10);
  this->set_ep(10);
  this->set_dmg(0);
}

ClapTrap::ClapTrap(std::string input) : _Name(input) {
  std::cout << "ClapTrap constructor called" << std::endl;
  this->set_name(input);
  this->set_hp(10);
  this->set_ep(10);
  this->set_dmg(0);
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor called" << std::endl; }

// claptrap foos

void ClapTrap::attack(const std::string &target) {
  if (_Hitpoints <= 0) {
    std::cout << this->get_name() << " doesn't have enought Hitpoints for anything"
              << std::endl;
    return;
  }
  if (_Energypoints <= 0) {
    std::cout << this->get_name() << " doesn't have enought energy for Attacking"
              << std::endl;
    return;
  }
  std::cout << this->get_name() << " attacks " << target << ", for "
            << this->get_dmg() << std::endl;
  this->use_energy();
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_Hitpoints <= 0) {
    std::cout << this->get_name() << " has already ceaced to function" << std::endl;
    return;
  }
  std::cout << this->get_name() << " gets hit for " << amount << std::endl;
  this->set_hp(this->get_hp() - amount);
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_Hitpoints <= 0) {
    std::cout << this->get_name() << " is already destroyed" << std::endl;
    return;
  }
  if (_Energypoints <= 0) {
    std::cout << this->get_name() << " doesn't have energy" << std::endl;
    return;
  }
  _Hitpoints += amount;
  this->use_energy();
  std::cout << this->get_name() << " has repaired " << amount << std::endl;
}

void ClapTrap::use_energy(void) { _Energypoints--; }
