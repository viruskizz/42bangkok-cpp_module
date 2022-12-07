#include "Convert.hpp"

int	main(int argc, char *argv[]) {
	if (argc == 1)
		return 0;
	Convert c = Convert(argv[1]);
	try {
		c.printCIDF();
		// c.printChar();
		// c.printInt();
		// c.printDouble();
		// c.printFloat();
	} catch (const std::exception& e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
