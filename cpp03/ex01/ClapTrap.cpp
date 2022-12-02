#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _maxHp(10), _hp(10), _maxMp(10), _mp(10), _atk(0) {
	std::cout << "ClapTrap - " << this->_name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	this->_maxHp = src._maxHp;
	this->_maxMp = src._maxMp;
	this->_atk = src._atk;
	this->_hp = src._hp;
	this->_mp = src._mp;
}


ClapTrap::~ClapTrap(void) {
	std::cout << "~ClapTrap - " << this->_name << " deconstructed" << std::endl;
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
