
#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {

private:

	AMateria*	_materias[4];

public:

	static int const size = 4;

	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	~MateriaSource(void);

	MateriaSource & operator=(MateriaSource const & rhs);

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const & type);
	AMateria*	getMateria(std::string const & type);

};

#endif
