#include "Zombie.hpp"

int main(void)
{
	Zombie *horde = NULL;

	horde = zombieHorde(5, "Isamar");
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Zombie # -> " << i + 1 << " named ";
		horde[i].announce();
	}
		delete[] horde;

	return (0);
}