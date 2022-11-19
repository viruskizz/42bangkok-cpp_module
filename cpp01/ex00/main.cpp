#include "Zombie.hpp"

int main(void) {
	Zombie*	zombie = new Zombie("Araiva");
	zombie->announce();
	delete zombie;
	
	Zombie* z = newZombie("new");
	z->announce();
	delete z;

	randomChump("random");

	return (0);
}
