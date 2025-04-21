#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie undead(name);
    undead.announce();
    return ;
}