#include "Bureaucrat.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name), _grade(grade) {
	if (this->_grade < Bureaucrat::highest)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > Bureaucrat::lowest)
		throw Bureaucrat::GradeTooLowException();
};

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string		Bureaucrat::getName() const {
	return this->_name;
}

unsigned int	Bureaucrat::getGrade() const {
	return this->_grade;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs ) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
void	Bureaucrat::increase() {
	if (this->_grade - 1 < Bureaucrat::highest)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrease() {
	if (this->_grade + 1 > Bureaucrat::lowest)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::validGradeRange(int g) {
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form & form) {
	try {
		form.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET <<std::endl;
	} catch (Form::GradeTooLowException & e) {
		std::cout << LRED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form) {
	try {
		form.execute(*this);
	}
	catch (const std::exception& e) {
		std::cout << LRED << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}