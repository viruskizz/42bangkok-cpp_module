#include "Intern.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
Intern::Intern() {};

Intern::~Intern() {}

Intern::Intern(Intern const & src) {
	*this = src;
}

Intern & Intern::operator=(Intern const & rhs) {
	(void) rhs;
	return *this;
}

/************************************************
 *           Specific member function           *
 ************************************************/
Form*	Intern::makeForm(std::string name, std::string target) {
	Form* forms[3] = { new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target) };
	std::string templates[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++) {
		if (templates[i] == name) {
			std::cout << GREEN << "Intern creates " << forms[i]->getName() << RESET << std::endl;
			for (int j = 0; j < 3; j++) { if (j != i) { delete forms[j]; } } // free other form
			return forms[i];
		}
	}
	for (int i = 0; i < 3; i++) { delete forms[i]; } // free all form
	std::cout << LRED << "form not found" << RESET << std::endl;
	return NULL;
}

