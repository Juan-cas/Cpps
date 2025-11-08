#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructor:

Character::Character(void) : ICharacter(), _Name("RandomNpc") {
  for (int i = 0; i < 4; i++) {
    _Inventory[i] = 0;
  }
  for (int i = 0; i < 20; i++) {
    _Floor[i] = 0;
  }
  return;
}

Character::Character(std::string str) : ICharacter(), _Name(str) {
  for (int i = 0; i < 4; i++) {
    _Inventory[i] = 0;
  }
  for (int i = 0; i < 20; i++) {
    _Floor[i] = 0;
  }
  return;
}

Character::Character(const Character &var) : ICharacter(var) {
  this->_Name = var.getName();
  for (int i = 0; i < 4; i++) {
    if (var._Inventory[i]) {
      _Inventory[i] = var._Inventory[i]->clone();
    }
  }
  for (int i = 0; i < 20; i++) {
    _Floor[i] = 0;
  }
}

Character::~Character(void) {
  for (int i = 0; i < 4; i++) {
    if (_Inventory[i]) {
      delete _Inventory[i];
      _Inventory[i] = 0;
    }
  }
  for (int i = 0; i < 20; i++) {
    if (_Floor[i]) {
      delete _Floor[i];
      _Floor[i] = 0;
    }
  }
  return;
}

// Overloads:

Character &Character::operator=(const Character &tmp) {
  if (this != &tmp) {
    this->_Name = tmp._Name;

    for (int i = 0; i < 4; i++) {
      if (_Inventory[i]) {
        delete _Inventory[i];
        _Inventory[i] = 0;
      }
    }

    for (int i = 0; i < 4; i++) {
      if (tmp._Inventory[i])
        this->_Inventory[i] = tmp._Inventory[i]->clone();
    }

    for (int i = 0; i < 20; i++) {
      _Floor[i] = 0;
    }
  }
  return (*this);
}

// Methods:

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (m == _Inventory[i]) {
      std::cout << "The materia is already equiped, please create another one "
                   "and equip the new one"
                << std::endl;
      return;
    }
    if (!_Inventory[i]) {
      _Inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4) {
    return;
  }
  if (!_Inventory[idx])
    return;
  for (int i = 0; i < 20; i++) {
    if (!_Floor[i]) {
      _Floor[i] = _Inventory[idx];
      _Inventory[idx] = NULL;
      return;
    }
  }
  delete _Floor[0];
  for (int i = 1; i < 20; i++) {
    _Floor[i - 1] = _Floor[i];
  }
  _Floor[19] = _Inventory[idx];
  _Inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx >= 4)
    return;
  if (_Inventory[idx])
    _Inventory[idx]->use(target);
}

std::string const &Character::getName() const { return _Name; }
