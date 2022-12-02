
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

protected:

	std::string		_name;
	unsigned int	_maxHp;
	int				_hp;
	unsigned int	_maxMp;
	int				_mp;
	int				_atk;

};

#endif
