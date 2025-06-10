#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void test3(void) {
  std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
  ClapTrap *ptr = new ScavTrap("PolyScav");
  ptr->attack("Vault Hunter");
  ptr->takeDamage(40);
  ptr->beRepaired(20);
  delete ptr; // Ensure destructor chaining works correctly
}

void test2(void) {
  std::cout << "\n=== TESTING SCAVTRAP ===" << std::endl;
  ScavTrap st("Scavvy");
  st.attack("Psycho");
  st.takeDamage(30);
  st.beRepaired(10);
  st.guardGate();
}

void test1(void) {
  std::cout << "=== TESTING CLAPTRAP ===" << std::endl;
  ClapTrap ct("Clappy");
  ct.attack("Bandit");
  ct.takeDamage(5);
  ct.beRepaired(3);
  ct.attack("Raider");
  ct.takeDamage(10);
  ct.beRepaired(5);
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
