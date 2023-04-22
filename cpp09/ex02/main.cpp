#include "PmergeMe.hpp"

int	main(int argc, char *argv[]) {
	if (argc < 2)
		return (std::cout << "Error" << std::endl, 1);
	try {
		PmergeMe nums = PmergeMe(argc, argv);
		std::cout << "Before: " << nums.getVtr() << std::endl;
		nums.sortVtr();
		nums.sortDck();
		std::cout << "After: " << nums.getVtr() << std::endl;
		nums.printVtrResult();
		nums.printDckResult();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}	
	return 0;
}
