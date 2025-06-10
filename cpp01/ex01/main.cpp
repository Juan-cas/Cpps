#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie *horde = NULL;

	horde = zombieHorde(5, "Isamaro");
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Zombie # -> " << i + 1 << " named ";
		horde[i].announce();
	}
		delete[] horde;

	return (0);
}
