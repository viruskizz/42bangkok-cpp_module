#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): Form(src) {
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "~Deconstructor~" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return this->_target;
}

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & rhs ) {
	o << rhs.getTarget() << " has been pardoned by Zaphod Beeblebrox";
	return o;
}


void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	std::cout << *this << std::endl;
}