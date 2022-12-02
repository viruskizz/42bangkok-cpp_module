#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap mario = ClapTrap("Mario");
	ScavTrap lugi = ScavTrap("Lugi");

	mario.attack("Z");
	lugi.attack("X");
	lugi.guardGate();
}
