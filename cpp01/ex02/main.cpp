#include <iostream>
#include <string>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPtr = &brain;
	std::string stringRef = brain;

	std::cout << &brain << std::endl;
	std::cout << &stringPtr << std::endl;
	std::cout << &stringRef << std::endl;

	std::cout << brain << std::endl;
	std::cout << *stringPtr << std::endl;
	std::cout << stringRef << std::endl;
}
