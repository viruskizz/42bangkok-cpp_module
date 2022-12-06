#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:

	std::string const	_name;
	bool				_signed;
	int unsigned const	_gradeToSign;
	int unsigned const	_gradeToExec;

public:

	static unsigned int const	lowest = 150;
	static unsigned int const	highest = 1;

	Form(std::string name, int gradeToSign);
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(Form const & src);
	~Form(void);

	Form & operator=(Form const & rhs);


	std::string		getName(void) const;
	bool			getSigned(void) const;
	unsigned int	getGradeToSign(void) const;
	unsigned int	getGradeToExec(void) const;

	void			beSigned(Bureaucrat const & bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too low"; }
	};
	class SignFormException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Invalid form signed"; }
	};

};

std::ostream & operator<<( std::ostream & o, Form const & rhs);

#endif
