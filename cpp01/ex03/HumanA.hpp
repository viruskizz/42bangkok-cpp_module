#ifndef HUMAN_A_H
# define HUMAN_A_H
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {

public:

	HumanA( std::string name, Weapon& wepon );
	~HumanA( void );

	void	attack( void );

private:

	std::string	_name;
	Weapon&		_weapon;

};

#endif
