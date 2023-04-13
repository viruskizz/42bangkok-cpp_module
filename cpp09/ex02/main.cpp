#include "PmergeMe.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2)
		return (std::cout << "Error" << std::endl, 1);
	try {
		PmergeMe nums = PmergeMe(argv[1]);
		std::cout << "Before: " << nums << std::endl;
		std::cout << "After: " << nums.getVtr() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}	
	return 0;
}
