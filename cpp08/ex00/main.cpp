#include "easyfind.hpp"
#include <cstdlib>
int main() {
	std::vector<int> v;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		v.push_back(rand() % 20);
	std::cout << v << std::endl;
	try {
		std::cout << easyfind(v, 5) << std::endl;
	} catch (NotFoundException & e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
