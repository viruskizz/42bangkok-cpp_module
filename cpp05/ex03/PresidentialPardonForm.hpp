#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include <iostream>
#include <string>
#include "Form.hpp"

class PresidentialPardonForm: public Form {

private:

	std::string	_target;

public:

	// PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);


	std::string	getTarget(void) const;
	void		execute(Bureaucrat const & executor) const;

};

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & rhs);

#endif
