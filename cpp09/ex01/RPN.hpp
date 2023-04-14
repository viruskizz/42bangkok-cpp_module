#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <cstdlib>

class RPN {

private:

	std::string		_input;
	std::stack<int>	_stk;
	int				_result;

	void			_cal(void);

public:

	RPN(void);
	RPN(std::string input);
	RPN(RPN const & src);
	~RPN(void);

	RPN & operator=(RPN const & rhs);


	std::string		getInput(void) const;
	std::stack<int>	getStk(void) const;
	int				getResult(void) const;

	class ErrorException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Error"; }
	};
};

std::ostream & operator<<( std::ostream & o, RPN const & rhs);
std::ostream & operator<<( std::ostream & o, std::stack<int> const & rhs );