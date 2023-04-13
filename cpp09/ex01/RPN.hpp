#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <deque>

class RPN {

protected:

	std::string		_input;
	std::deque<int>	_deck;
	int				_result;

	void			_cal(void);
public:

	RPN(void);
	RPN(std::string input);
	RPN(RPN const & src);
	~RPN(void);

	RPN & operator=(RPN const & rhs);


	std::string		getInput(void) const;
	std::deque<int>	getDeck(void) const;
	int				getResult(void) const;

	class ErrorException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Error"; }
	};
};

std::ostream & operator<<( std::ostream & o, RPN const & rhs);
std::ostream & operator<<( std::ostream & o, std::deque<int> const & rhs );