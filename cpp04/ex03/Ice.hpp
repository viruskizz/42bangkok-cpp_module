#ifndef ICE_H
#define ICE_H

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice: public AMateria {

public:

	Ice(void);
	Ice(Ice const & src);
	~Ice(void);

	AMateria*	clone() const;
	void	use(ICharacter& target);

};

#endif
