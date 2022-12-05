#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << this->_type << " constructor is called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src) {
	*this = src;
}

Dog::~Dog() {
	std::cout << this->_type << " deconstructor is called" << std::endl;
	delete this->_brain;
}

Dog &	Dog::operator=( Dog const & rhs ) {
	std::cout << "Dog assignment operator is called";
	if (this == &rhs)
		return *this;
	this->_type = rhs.getType();
	this->_brain = rhs._brain;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Just " << this->getType() << std::endl;
}