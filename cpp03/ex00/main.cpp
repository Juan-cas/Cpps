

#include "ClapTrap.hpp"


int main ()
{
	ClapTrap robot("Eldorado");

	robot.attack("ElmenosDorado");
	robot.attack("ElmenosDorado");
	robot.beRepaired(5);
	robot.beRepaired(5);
	robot.beRepaired(5);
	robot.beRepaired(5);
	robot.takeDamage(20);
	robot.takeDamage(20);
	robot.attack("ElmenosDorado");
	robot.attack("ElmenosDorado");
	robot.attack("ElmenosDorado");
	robot.attack("ElmenosDorado");
	robot.attack("ElmenosDorado");
	robot.attack("ElmenosDorado");
	return 0;
}
