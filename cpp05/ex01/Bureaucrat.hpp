#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include "Form.hpp"

# define LRED		"\033[0;91m"
# define YELLOW		"\033[0;33m"
# define GREEN		"\033[0;32m"
# define RESET		"\033[0m"

class Form;

class Bureaucrat {

private:

	std::string const	_name;
	unsigned int		_grade;

public:

	static unsigned int const	lowest = 150;
	static unsigned int const	highest = 1;

	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat & operator=(Bureaucrat const & rhs);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

	void	increase(void);
	void	decrease(void);
	void	validGradeRange(int g);
	void	signForm(Form & form);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too high"; }
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Grade too low"; }
	};

};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif
