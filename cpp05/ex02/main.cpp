#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	try {
		Bureaucrat	a = Bureaucrat("A", 1);
		Bureaucrat	b = Bureaucrat("Bad", 100);
		Bureaucrat	c = Bureaucrat("Cat", 150);
		Form *pForm = new PresidentialPardonForm("Pres");	// requied grade  25
		Form *rForm = new RobotomyRequestForm("Robot");		// requied grade  72
		Form *sForm = new ShrubberyCreationForm("Shub");	// requied grade 145
		pForm->execute(a);
		rForm->execute(a);
		sForm->execute(a);
		// c.executeForm(*sForm); // Fail
		// c.executeForm(*rForm); // Fail
		// c.executeForm(*pForm); // Fail
	} catch (std::exception &e) {
		std::cout << "catch main" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return 0;
}