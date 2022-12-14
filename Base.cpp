#include "Base.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
Base::Base(): _name("") {
	std::cout << "Default constructor overload" << std::endl;
	std::cout << "" << std::endl;
};

Base::Base(std::string name): _name(name){
	std::cout << "Argument constructor overload" << std::endl;
};

Base::Base(Base const & src) {
	std::cout << "Copy constructor overload" << std::endl;
	*this = src;
}

Base & Base::operator=(Base const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
		
	this->_name = rhs._name;
	return *this;
}

Base::~Base() {
	std::cout << "~Deconstructor~" << std::endl;
}

std::string	Base::getName() const {
	return this->_name;
}

std::ostream & operator<<( std::ostream & o, Base const & rhs ) {
	o << rhs.getName();
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
