#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* cat = new Cat();
	Animal* dog = new Dog();

	delete cat;
	delete dog;

	int n = 4;
	Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for (int i = 0; i < n; i++) {
		delete animals[i];
	}

	return 0;
}
