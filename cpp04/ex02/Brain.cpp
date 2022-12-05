#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor is called" << std::endl;
}

Brain::Brain(Brain const & src) {
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain  deconstructor is called" << std::endl;
}

Brain &	Brain::operator=( Brain const & rhs ) {
	std::cout << "Brain assignment operator is called";
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}
