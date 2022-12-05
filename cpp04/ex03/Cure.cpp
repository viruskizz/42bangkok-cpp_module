#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure const & src) {
	*this = src;
}

Cure::~Cure() {}

AMateria*	Cure::clone() const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds. *" << std::endl;
}

