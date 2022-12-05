#ifndef CURE_H
#define CURE_H

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure: public AMateria {

public:

	Cure(void);
	Cure(Cure const & src);
	~Cure(void);

	AMateria*	clone() const;
	void	use(ICharacter& target);

};

#endif
