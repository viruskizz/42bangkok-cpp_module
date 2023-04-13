#pragma once

#include <iostream>
#include <string>

class RPN {

protected:

	std::string	_name;

public:

	RPN(void);
	RPN(std::string name);
	RPN(RPN const & src);
	~RPN(void);

	RPN & operator=(RPN const & rhs);


	std::string	getName(void) const;

};

std::ostream & operator<<( std::ostream & o, RPN const & rhs);
