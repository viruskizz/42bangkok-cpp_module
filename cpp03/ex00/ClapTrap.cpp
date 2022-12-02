#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name) {
	std::cout << "Default construct has been called" << std::endl;
	this->_maxHp = 10;
	this->_maxMp = 10;
	this->_atk = 0;
	this->_hp = this->_maxHp;
	this->_mp = this->_maxMp;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	this->_maxHp = src._maxHp;
	this->_maxMp = src._maxMp;
	this->_atk = src._atk;
	this->_hp = src._hp;
	this->_mp = src._mp;
}


ClapTrap::~ClapTrap(void) {
	std::cout << "Deconstruct has been called" << std::endl;
}

ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs ) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (!this->isAlive())
		return;
	this->_mp -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_atk << " points of damage!" << std::endl;
}


void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->isAlive())
		return;
	unsigned int restore;
	if (this->_hp + amount > this->_maxHp)
		restore = this->_maxHp;
	else
		restore = this->_hp + amount;
	this->_hp = restore;
	this->_mp -= 1;
}

bool	ClapTrap::isAlive(void) {
	return (this->_hp > 0 && this->_mp > 0);
}
