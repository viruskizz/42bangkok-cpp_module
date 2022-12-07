#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm: public Form {

private:

	std::string	_target;

public:

	// RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);


	std::string	getTarget(void) const;
	void		execute(Bureaucrat const & executor) const;

};

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm const & rhs);

#endif
