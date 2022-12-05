#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {

public:

	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const & src);
	~WrongAnimal(void);

	WrongAnimal &	operator=(WrongAnimal const & rhs);

	// virtual void	makeSound(void) const = 0; // compile error with pure funciton
	virtual void	makeSound(void) const;
	std::string		getType(void) const;

protected:

	std::string _type;

};

#endif