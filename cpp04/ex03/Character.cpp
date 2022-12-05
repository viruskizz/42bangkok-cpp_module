#include "Character.hpp"

Character::Character(std::string name): _name(name) {
	for (int i = 0; i< Character::slotSize; i++) {
		this->_equiped[i] = NULL;
	}
};

Character::Character(Character const & src) {
	*this = src;
}

Character & Character::operator=(Character const & rhs) {
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	for (int i = 0; i < Character::slotSize; i++) {
		if (rhs._equiped[i])
			this->_equiped[i] = rhs._equiped[i];
	}
	return *this;
}

Character::~Character() {
	std::cout << this->getName() << " is destroy" << std::endl;
	for (int i = 0; i < Character::slotSize; i++) {
		if (this->_equiped[i])
			delete this->_equiped[i];
	}
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < Character::slotSize; i++) {
		if (this->_equiped[i] == NULL) {
			this->_equiped[i] = m;
			return ;
		}
	}
	std::cout << this->getName() << "Cannot equip " << m->getType() << ", ";
	std::cout << this->getName() <<"'s slot is full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > Character::slotSize)
		return ;
	if (this->_equiped[idx]) {
		delete this->_equiped[idx];
		this->_equiped[idx] = NULL;
		std::cout << "Unequiped: [" << idx << "]" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > Character::slotSize)
		return ;
	if (this->_equiped[idx])
		this->_equiped[idx]->use(target);
	else
		std::cout << "[" << idx << "] Not equiped" << std::endl;
}
