
#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

# define GREEN		"\033[0;32m"
# define RESET		"\033[0m"

class FragTrap : public ClapTrap {

public:

	FragTrap(std::string name);
	~FragTrap(void);

	void	highFivesGuys(void);

};

#endif
