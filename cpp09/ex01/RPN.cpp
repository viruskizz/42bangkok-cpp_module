#include "RPN.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
RPN::RPN(): _name("") {
	std::cout << "Default constructor overload" << std::endl;
	std::cout << "" << std::endl;
};

RPN::RPN(std::string name): _name(name){
	std::cout << "Argument constructor overload" << std::endl;
};

RPN::RPN(RPN const & src) {
	std::cout << "Copy constructor overload" << std::endl;
	*this = src;
}

RPN & RPN::operator=(RPN const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
		
	this->_name = rhs._name;
	return *this;
}

RPN::~RPN() {
	std::cout << "~Deconstructor~" << std::endl;
}

std::string	RPN::getName() const {
	return this->_name;
}

std::ostream & operator<<( std::ostream & o, RPN const & rhs ) {
	o << rhs.getName();
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
