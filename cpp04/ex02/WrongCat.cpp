#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << this->_type << " constructor is called" << std::endl;
}
WrongCat::~WrongCat() {}
