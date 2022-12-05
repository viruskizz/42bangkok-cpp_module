#ifndef CAT_H
# define CAT_H

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {

public:

	Cat(void);
	~Cat(void);

	Cat(Cat const & src);

	Cat &	operator=(Cat const & rhs);

	void	makeSound(void) const;

private:

	Brain	*_brain;

};

#endif
