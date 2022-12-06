#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name), _grade(grade) {
	if (this->_grade < Bureaucrat::highest)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > Bureaucrat::lowest)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Argument constructor overload" << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	std::cout << "Copy constructor overload" << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "~Deconstructor~" << std::endl;
}


std::string		Bureaucrat::getName() const {
	return this->_name;
}

unsigned int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void			Bureaucrat::increase() {
	if (this->_grade - 1 < Bureaucrat::highest)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void			Bureaucrat::decrease() {
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

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs ) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
