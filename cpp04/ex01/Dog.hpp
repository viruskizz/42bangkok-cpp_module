#ifndef DOG_H
# define DOG_H

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {

public:

	Dog(void);
	~Dog(void);
	Dog(Dog const & src);

	Dog &	operator=(Dog const & rhs);

	void	makeSound(void) const;

private:

	Brain	*_brain;

};

#endif