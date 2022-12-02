#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap - " << this->_name << " constructed" << std::endl;
	this->_maxHp = 100;
	this->_maxMp = 50;
	this->_atk = 20;
	this->_hp = this->_maxHp;
	this->_mp = this->_maxMp;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap - " << this->_name << " destructed" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (!this->isAlive())
		return;
	this->_mp -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_atk << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << LRED << "ScavTrap " << this->_name << " is now in Gate keeper mode." << RESET << std::endl;
}
