#include "Zombie.hpp"

int main(void) {
	Zombie*	zombie = new Zombie();

	zombie->announce();
	delete zombie;

	return (0);
}
