#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << this->_type << " constructor is called" << std::endl;
}
WrongCat::~WrongCat() {}

void	WrongCat::makeSound() const {
	std::cout << "Just " << this->getType() << std::endl;
}
