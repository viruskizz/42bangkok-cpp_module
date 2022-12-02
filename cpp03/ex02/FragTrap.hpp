
#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

# define LRED		"\033[0;91m"
# define RESET		"\033[0m"

class FragTrap : public ClapTrap {

public:

	FragTrap(std::string name);
	~FragTrap(void);

	void	highFivesGuys(void);

};

#endif
