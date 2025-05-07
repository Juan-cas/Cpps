#include "MateriaSource.hpp"
#include <iostream>

// Constructor
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _materias[i] = 0;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &var) {
    for (int i = 0; i < 4; ++i) {
        if (var._materias[i])
            _materias[i] = var._materias[i]->clone();
        else
            _materias[i] = 0;
    }
}

// Destructor
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete _materias[i];
    }
}

// Assignment operator
MateriaSource &MateriaSource::operator=(const MateriaSource &tmp) {
    if (this != &tmp) {
        for (int i = 0; i < 4; ++i) {
            delete _materias[i];  // clean old materia
            if (tmp._materias[i])
                _materias[i] = tmp._materias[i]->clone();
            else
                _materias[i] = 0;
        }
    }
    return *this;
}

// Learn a new materia (store pointer)
void MateriaSource::learnMateria(AMateria *m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!_materias[i]) {
            _materias[i] = m;
            return;
        }
    }
    std::cout << "Cannot learn more materia, storage full!" << std::endl;
}

// Create a materia by type
AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] && _materias[i]->getType() == type) {
            return _materias[i]->clone();
        }
    }
    std::cout << "Materia type [" << type << "] not found." << std::endl;
    return 0;
}
