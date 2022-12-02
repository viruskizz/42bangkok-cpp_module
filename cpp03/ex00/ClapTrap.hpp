
#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

#include <iostream>
#include <string>

class ClapTrap {

public:

	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);

	ClapTrap &	operator= (ClapTrap const & rhs);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	bool	isAlive(void);

private:

	std::string		_name;
	unsigned int	_maxHp;
	unsigned int	_maxMp;
	int				_hp;
	int				_mp;
	int				_atk;
}; 

#endif
