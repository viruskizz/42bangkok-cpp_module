#include "identify.hpp"

int	main() {
	Base *base[10];\
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		base[i] = generate();
		std::cout << i << "* = "; identify(base[i]);
		std::cout << i << "& = "; identify(*base[i]);
	}
	for (int i = 0; i < 10; i++) {
		delete base[i];
	}
	return 0;
}
