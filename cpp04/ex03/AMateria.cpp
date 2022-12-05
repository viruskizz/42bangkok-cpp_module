#include "AMateria.hpp"

AMateria::AMateria(): _type("") {}

AMateria::AMateria(std::string const & type): _type(type) {}

AMateria::AMateria(AMateria const & src) {
	*this = src;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::setType(std::string const & type) {
	this->_type = type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* use " << this->_type << " at " << target.getName() << " *" << std::endl;
}
