#include <iostream>
#include <cctype>

void	print_uppercase_str(char *str);

int	main(int argc, char *argv[]) {
	if (argc == 1) {
		const char *msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << msg << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			print_uppercase_str(argv[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}

void	print_uppercase_str(char *str) {
	while (*str) {
		std::cout << (char) toupper(*str++);
	}
}
