
#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {

public:

	Zombie(std::string name = "default");
	~Zombie ( void );

	void	announce( void );
	void	setName( std::string name );

private:

	std::string	_name;

};

Zombie* zombieHorde( int N, std::string name );

#endif
