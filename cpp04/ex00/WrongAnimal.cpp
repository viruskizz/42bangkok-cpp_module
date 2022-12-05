#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
	std::cout << this->_type << " constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << "WrongAnimal: "<< this->_type << " constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	this->_type = src._type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << this->_type << " deconstructor is called" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & rhs ) {
	if (this != &rhs)
		*this = rhs;
	std::cout << "WrongAnimal assignment operator is called";
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Just WrongAnimal" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->_type;
}
