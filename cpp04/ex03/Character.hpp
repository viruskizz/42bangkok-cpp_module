#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character: public ICharacter {

private:

	std::string	_name;
	AMateria *_equiped[4];

public:

	static int const slotSize = 4;

	Character(std::string name);
	Character(Character const & src);
	~Character();

	Character & operator=(Character const & rhs);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif
