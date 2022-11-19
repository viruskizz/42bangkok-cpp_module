#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << "is died" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	Zombie::newZombie( std::string name )
{
	Zombie *zombie = new Zombie();
	zombie->_name = name;
	return zombie; 
}

void	Zombie::randomChump( std::string name )
{
	Zombie*	zombie;
	zombie = newZombie(name);
	zombie->announce();
}