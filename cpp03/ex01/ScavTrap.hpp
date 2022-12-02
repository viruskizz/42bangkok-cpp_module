
#ifndef SCRAV_TRAP_H
# define SCRAV_TRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

# define LRED		"\033[0;91m"
# define RESET		"\033[0m"

class ScavTrap : public ClapTrap {

public:

	ScavTrap(std::string name);
	~ScavTrap(void);

	void	attack(const std::string& target);
	void	guardGate(void);

};

#endif
