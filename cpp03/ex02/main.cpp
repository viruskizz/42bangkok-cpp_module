#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap mario = ClapTrap("Mario");
	FragTrap lugi = FragTrap("Lugi");

	mario.attack("Z");
	lugi.attack("X");
	lugi.highFivesGuys();
}
