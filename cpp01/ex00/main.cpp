#include "Zombie.hpp"
#include <iostream>

int main(void) {
  Zombie long_lived_zombie = Zombie("Roberto");
  std::cout << "a random chump is spawning" << std::endl;
  randomChump("ARM ando");
  std::cout << "the random chump should have died" << std::endl;

  std::cout << "the long lived zombie: " << long_lived_zombie.Zombie::get_name()
            << " is reaching his end." << std::endl;
  return (0);
}
