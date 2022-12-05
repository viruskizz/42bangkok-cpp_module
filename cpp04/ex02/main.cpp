#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	AAnimal* cat = new Cat();
	AAnimal* dog = new Dog();

	delete cat;
	delete dog;

	int n = 4;
	AAnimal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for (int i = 0; i < n; i++) {
		delete animals[i];
	}

	// Test pure function abstruct class
	std::cout << "\n=================================\n" << std::endl;
	WrongAnimal *wc = new WrongCat();
	wc->makeSound();
	return 0;
}
