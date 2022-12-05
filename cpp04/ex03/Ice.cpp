#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const & src) {
	*this = src;
}

Ice::~Ice() {}

AMateria*	Ice::clone() const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shots an " << this->_type <<" bolt at " << target.getName() << " *" << std::endl;
}

// void Ice::setType(std::string const & type) {
// 	this->_type = type;
// }
