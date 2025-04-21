#include "Zombie.hpp"

int main(void)
{
	Zombie* long_lived_zombie = NULL;

	long_lived_zombie = newZombie("Roberto");
	long_lived_zombie->randomChump("ARM ando");
	std::cout << "the long lived zombie: " << long_lived_zombie->Zombie::get_name() << " is reaching his end." << std::endl;
	delete long_lived_zombie;
	return (0);
}