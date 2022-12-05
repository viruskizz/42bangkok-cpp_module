#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << this->_type << " constructor is called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const & src) {
	*this = src;
}

Cat::~Cat() {
	std::cout << this->_type << " deconstructor is called" << std::endl;
	delete this->_brain;
}

Cat &	Cat::operator=( Cat const & rhs ) {
	std::cout << "Cat assignment operator is called";
	if (this == &rhs)
		return *this;
	this->_type = rhs.getType();
	this->_brain = rhs._brain;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Just " << this->getType() << std::endl;
}
