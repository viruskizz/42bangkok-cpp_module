#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): Form(src) {
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget() const {
	return this->_target;
}

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm const & rhs ) {
	o << rhs.getTarget() << " has been signed by Robotomy";
	return o;
}


void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	srand(time(NULL));
	if ( rand() % 2 == 0)
		std::cout << *this << std::endl;
	else
		std::cout << executor.getName() << " is fail by Robot" << std::endl;
}
