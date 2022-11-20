#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc > 1)
		Harl::complainFilter(argv[1]);
	return 0;
}