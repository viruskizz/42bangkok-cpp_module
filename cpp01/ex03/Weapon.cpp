#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

Weapon::~Weapon() {}

std::string const &	Weapon::getType() const
{
	return this->_type;
}

void	Weapon::setType( std::string str )
{
	this->_type = str;

}
