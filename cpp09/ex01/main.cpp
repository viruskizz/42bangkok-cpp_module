#include "RPN.hpp"

int	main(int argc, char *argv[]) {
	if (argc == 1)
		return (std::cerr << "Error: need 1 argument" << std::endl, 1);
	if (argc != 2)
		return (std::cerr << "Error: need 1 argument" << std::endl, 1);
	try {
		RPN rpn = RPN(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
