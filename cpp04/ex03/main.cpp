#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	me->equip(ice);
	me->equip(cure);
	me->use(0, *me);
	me->use(1, *me);
	me->unequip(1);
	me->use(1, *me);

	// default main.c
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// me->use(0, *bob);
	// me->use(1, *bob);
	// delete bob;
	// delete me;
	delete src;
	delete me;
	delete bob;
	return 0;
}
