#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cassert>

int	main() {
	Bureaucrat *	Donald = new Bureaucrat("Donald", 2);
	Bureaucrat *	Joe = new Bureaucrat("Joe", 10);
	Bureaucrat *	Miguel = new Bureaucrat("Miguel", 65);
	Intern *		nobody = new Intern();
	AForm *			shru = new Shrubbery("joe");
	AForm *			robot = new RobotomyForm("Donald");
	AForm *			ppf = NULL;

	try {
		ppf = nobody->makeForm("presidential request", "joe");
		robot->beSigned(*Miguel);
		shru->beSigned(*Joe);
		ppf->beSigned(*Joe);
		robot->beExcecuted(*Donald);
		shru->beExcecuted(*Donald);
		ppf->beExcecuted(*Donald);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;

	delete ppf;
	delete robot;
	delete shru;
	delete nobody;
	delete Miguel;
	delete Joe;
	delete Donald;
}
