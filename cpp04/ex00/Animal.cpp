#include "Animal.hpp"

Animal::Animal(): _type("Animal") {
	std::cout << this->_type << " constructor is called" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal: " << this->_type << " constructor is called" << std::endl;
}

Animal::Animal(Animal const & src) {
	this->_type = src._type;
}

Animal::~Animal() {
	std::cout << "Animal: " << this->_type << " deconstructor is called" << std::endl;
}

Animal &	Animal::operator=( Animal const & rhs ) {
	if (this != &rhs)
		*this = rhs;
	std::cout << "Animal assignment operator is called";
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "Just Animal" << std::endl;
}

std::string	Animal::getType() const {
	return this->_type;
}
