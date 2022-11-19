#include <iostream>
#include <cctype>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	str_compare(const char *s1, const char *s2);

int	main(void) {
	std::string	input;
	PhoneBook	phbook;
	
	while (true) {
		std::cout << "$ ";
		if (!std::getline (std::cin, input))
			break;
		if (str_compare(&input[0], "ADD") == 0) {
			phbook.display_add();
		} else if (str_compare(&input[0], "SEARCH") == 0) {
			phbook.display_search();
		} else if (str_compare(&input[0], "EXIT") == 0) {
			std::cout << "BYE!!" << std::endl;
			break;
		}
		std::cin.clear();
	}
	std::cin.clear();
	return (0);
}

int	str_compare(const char *s1, const char *s2) {
	while (*s1 || *s2) {
		if (toupper(*s1) != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}
	return (0);
}
