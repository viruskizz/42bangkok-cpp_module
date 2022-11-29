#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPoint( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _fixedPoint( 0 ) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPoint = rhs.getRawBits();
	return *this;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPoint = raw;
}
