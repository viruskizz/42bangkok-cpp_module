#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("AAnimal") {
	std::cout << this->_type << " constructor is called" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type) {
	std::cout << "AAnimal: " << this->_type << " constructor is called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) {
	this->_type = src._type;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal: " << this->_type << " deconstructor is called" << std::endl;
}

AAnimal &	AAnimal::operator=( AAnimal const & rhs ) {
	if (this != &rhs)
		*this = rhs;
	std::cout << "AAnimal assignment operator is called";
	return *this;
}

void	AAnimal::makeSound() const {
	std::cout << "Just AAnimal" << std::endl;
}

std::string	AAnimal::getType() const {
	return this->_type;
}
