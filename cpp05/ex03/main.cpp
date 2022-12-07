#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "======= INTERN =======" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;
		Form* rrr;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrr = someRandomIntern.makeForm("robotomy  abd request", "Araiva");
		std::cout << *rrf << std::endl;
		// std::cout << *rrr << std::endl;
		delete rrr;
		delete rrf;
	}
	std::cout << "======= FORM =======" << std::endl;
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

		delete pForm;
		delete rForm;
		delete sForm;
	} catch (std::exception &e) {
		std::cout << "catch main" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}