#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): Form(src) {
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & rhs ) {
	o << GREEN << rhs.getTarget() << " has been signed by Robotomy" << RESET;
	return o;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream file;
	file.open(filename.c_str());
	if (file.is_open()) {
		file << tree;
		file.close();
		std::cout << GREEN << filename << RESET << " has been created" << std::endl;
  	} else {
		std::cout << "Unable to open file";
	}
}
