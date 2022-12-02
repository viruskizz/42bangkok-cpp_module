#include "DiamondTrap.hpp"
// https://stackoverflow.com/questions/2659116/how-does-virtual-inheritance-solve-the-diamond-multiple-inheritance-ambiguit

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap - " << this->_name << " constructed" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	FragTrap::_maxHp = 100;
	ScavTrap::_maxMp = 50;
	FragTrap::_atk = 30;
	FragTrap::_hp = FragTrap::_maxHp;
	ScavTrap::_mp = ScavTrap::_maxMp;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap - " << this->_name << " destructed" << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I'am DiamondTrap-" << this->_name << " from ClapTrap-" << this->ClapTrap::_name << std::endl;
}
