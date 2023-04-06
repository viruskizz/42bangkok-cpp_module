#include <iostream>
#include <stdexcept>
#include <string>

int main() {
	int point;
	point = -1;
	if (point < 0)
		throw std::out_of_range("point cannot lower than 0");
	std::cout << "Good Grade" << std::endl;

	try {
		if (point < 0)
			throw std::out_of_range("point cannot lower than 0");
		std::cout << "Good Grade" << std::endl;
	} catch (std::out_of_range& e) {
		std::cout << "Error" << std::endl;
	}
	std::cout << "Finish" << std::endl;
	return 0;
}
