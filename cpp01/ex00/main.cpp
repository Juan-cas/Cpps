#include "Zombie.hpp"
#include <iostream>

int main(void) {
  std::cout << "spawning long lived zombi\n" << std::endl;
  Zombie long_lived_zombie = Zombie("Roberto");

  std::cout << "spawning the pointer zombie\n" << std::endl;
  Zombie *zomboid = newZombie("zomboid");
  zomboid->announce();

  std::cout << "\ncreating a random chump" << std::endl;
  randomChump("ARM ando");
  std::cout << "the random chump should have died" << std::endl;
  std::cout << "the long lived zombie: " << long_lived_zombie.Zombie::get_name()
            << " is reaching his end." << std::endl;

  std::cout << "\n deleting the pointer zombi" << std::endl;
  delete zomboid;
  return (0);
}
