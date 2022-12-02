#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap - " << this->_name << " constructed" << std::endl;
	this->_maxHp = 100;
	this->_maxMp = 50;
	this->_atk = 20;
	this->_hp = this->_maxHp;
	this->_mp = this->_maxMp;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap - " << this->_name << " destructed" << std::endl;
}

void	FragTrap::highFivesGuys() {
	if (!this->isAlive())
		return;
	this->_mp -= 1;
	std::cout << GREEN << "FragTrap " << this->_name << " high fives everyone." << RESET << std::endl;
}
