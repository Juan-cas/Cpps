#include "Zombie.hpp"

void Zombie::announce() const
{
	std::cout << this->name << " YELLS: BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "A new Zombie has spawned named " << this->name << " beware." << std::endl;
}

void Zombie::set_name(const str& name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "A Zombie named: " << this->name << " has died." << std::endl;
}

std::string Zombie::get_name() const
{
	return (this->name);
}
