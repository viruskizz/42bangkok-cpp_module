#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>
#include <string>

class AAnimal {

public:

	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(AAnimal const & src);
	// ~AAnimal(void);
	virtual ~AAnimal(void);

	AAnimal &	operator=(AAnimal const & rhs);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;

protected:

	std::string _type;

};

#endif