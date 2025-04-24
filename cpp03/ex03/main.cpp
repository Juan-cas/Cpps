#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
  std::cout << "=== TESTING CLAPTRAP ===" << std::endl;
  ClapTrap ct("Clappy");
  ct.attack("Bandit");
  ct.takeDamage(5);
  ct.beRepaired(3);
  ct.attack("Raider");
  ct.takeDamage(10);
  ct.beRepaired(5);

  std::cout << "\n=== TESTING SCAVTRAP ===" << std::endl;
  ScavTrap st("Scavvy");
  st.attack("Psycho");
  st.takeDamage(30);
  st.beRepaired(10);
  st.guardGate();

  std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
  ClapTrap *ptr = new ScavTrap("PolyScav");
  ptr->attack("Vault Hunter");
  ptr->takeDamage(40);
  ptr->beRepaired(20);
  delete ptr; // Ensure destructor chaining works correctly

  std::cout << "\n====== testing frag trap ======\n";
  // Create a FragTrap instance
  FragTrap frag("Fraggy");

  // Test attacks
  frag.attack("Enemy1");
  frag.attack("Enemy2");

  // Test taking damage
  frag.takeDamage(25);

  // Test repairing
  frag.beRepaired(15);

  // Test high fives
  frag.highFivesdGuys();

  // Destroy the object (this will call the destructor)
  std::cout << "\n====== Diamond trap ======\n";

  DiamondTrap *dt = new DiamondTrap("Diamy");
  dt->get_name();
  dt->whoami();
  dt->attack("a sturdy wall");
  dt->highFivesdGuys();
  dt->guardGate();
  dt->get_ep();
  dt->beRepaired(10);
  dt->get_ep();
  delete dt;
  return 0;
}
