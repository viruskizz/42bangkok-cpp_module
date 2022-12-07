#ifndef INTERN_H
#define INTERN_H

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

public:

	Intern(void);
	~Intern(void);
	Intern(Intern const & src);

	Intern & operator=(Intern const & rhs);

	Form*	makeForm(std::string name, std::string target);

};

#endif
