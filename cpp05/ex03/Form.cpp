#include "Form.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
Form::Form(std::string name, int gradeToSign): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(0) {
	if (this->_gradeToSign < Form::highest)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > Form::lowest)
		throw Form::GradeTooLowException();
};

/* Do not use */
Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (this->_gradeToSign < Form::highest)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > Form::lowest)
		throw Form::GradeTooLowException();
	if (this->_gradeToExec < this->getGradeToSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
};

Form::Form(Form const & src): _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {}

Form & Form::operator=(Form const & rhs) {
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const {
	return this->_name;
}
bool	Form::getSigned() const {
	return this->_signed;
}
unsigned int	Form::getGradeToSign() const {
	return this->_gradeToSign;
}
unsigned int	Form::getGradeToExec() const {
	return this->_gradeToExec;
}

std::ostream & operator<<( std::ostream & o, Form const & rhs ) {
	o << rhs.getName() << "-Form: " << rhs.getGradeToSign() << "<" << rhs.getGradeToExec();
	if (rhs.getSigned())
		o << GREEN << " [OK]" << RESET;
	else
		o << LRED << " [NO]" << RESET;
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
/**
 * -> 1
 * -> 2
 * -> 3  <== Required upper
 * -> 4
 * -> 5
*/
void	Form::beSigned(Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() < this->getGradeToSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}