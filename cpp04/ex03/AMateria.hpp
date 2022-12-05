#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:

	std::string	_type;

public:

	AMateria(void);
	AMateria(std::string const & type);
	AMateria(AMateria const & src);
	virtual ~AMateria(void);

	std::string const & getType() const;
	void setType(std::string const & type);

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif
