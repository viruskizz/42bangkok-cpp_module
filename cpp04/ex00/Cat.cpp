#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << this->_type << " constructor is called" << std::endl;
}
Cat::~Cat() {
	std::cout << this->_type << " deconstructor is called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Just " << this->getType() << std::endl;
}
