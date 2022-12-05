#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << this->_type << " constructor is called" << std::endl;
}
Dog::~Dog() {
	std::cout << this->_type << " deconstructor is called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Just " << this->getType() << std::endl;
}