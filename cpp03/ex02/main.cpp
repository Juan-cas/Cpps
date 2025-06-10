#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void test4() {
  std::cout << "\n====== testing frag trap ======\n";
  FragTrap frag("Fraggy");
  frag.attack("Enemy1");
  frag.attack("Enemy2");
  frag.takeDamage(25);
  frag.beRepaired(15);
  frag.highFivesdGuys();
  std::cout << "\n==== Finishing test====\n" << std::endl;
}

void test3() {
  std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
  ClapTrap *ptr = new ScavTrap("PolyScav");
  ptr->attack("Vault Hunter");
  ptr->takeDamage(40);
  ptr->beRepaired(20);
  delete ptr;
  std::cout << "\n==== Finishing test====\n" << std::endl;
}

void test2() {
  std::cout << "\n=== TESTING SCAVTRAP ===" << std::endl;
  ScavTrap st("Scavvy");
  st.attack("Psycho");
  st.takeDamage(30);
  st.beRepaired(10);
  st.guardGate();
  std::cout << "\n==== Finishing test====\n" << std::endl;
}

void test1() {
  std::cout << "=== TESTING CLAPTRAP ===" << std::endl;
  ClapTrap ct("Clappy");
  ct.attack("Bandit");
  ct.takeDamage(5);
  ct.beRepaired(3);
  ct.attack("Raider");
  ct.takeDamage(10);
  ct.beRepaired(5);
  std::cout << "\n==== Finishing test====\n" << std::endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();

  return 0;
}
