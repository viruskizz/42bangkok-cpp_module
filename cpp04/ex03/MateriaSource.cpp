#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i< MateriaSource::size; i++) {
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	*this = src;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < MateriaSource::size; i++) {
		if (this->_materias[i])
			delete this->_materias[i];
	}
	std::cout << "Destroy meteria source" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	if (this == &rhs)
		return *this;
	for (int i = 0; i < MateriaSource::size; i++) {
		if (rhs._materias[i])
			this->_materias[i] = rhs._materias[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MateriaSource::size; i++) {
		if (!this->_materias[i]) {
			this->_materias[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MateriaSource::size; i++) {
		if (this->_materias[i] && this->getMateria(type)) {
			return this->_materias[i]->clone();
		}
	}
	return NULL;
}

AMateria* MateriaSource::getMateria(std::string const & type) {
	for (int i = 0; i < MateriaSource::size; i++) {
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return this->_materias[i];
	}
	return NULL;
}
