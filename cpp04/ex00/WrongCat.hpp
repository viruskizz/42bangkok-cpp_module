#ifndef WRONG_CAT_H
# define WRONG_CAT_H

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {

public:

	WrongCat(void);
	~WrongCat(void);

	void	makeSound(void) const;

};

#endif
