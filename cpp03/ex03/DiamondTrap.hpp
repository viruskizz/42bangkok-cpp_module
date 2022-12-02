
#ifndef DIAMOND_TRAP_H
# define DIAMOND_TRAP_H

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

# define LRED		"\033[0;91m"
# define RESET		"\033[0m"

class DiamondTrap : public ScavTrap, public FragTrap {

public:

	DiamondTrap(std::string name);
	~DiamondTrap(void);

	using	ScavTrap::attack;
	void	whoAmI();

private:

	std::string	_name;

};

#endif
