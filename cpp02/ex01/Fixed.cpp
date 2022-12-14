#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPoint( 0 ) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const n ) : _fixedPoint( n << _fractionalBit ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const n ) : _fixedPoint( roundf( n * ( 1 << _fractionalBit )) ) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _fixedPoint( 0 ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
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
	return this->_fixedPoint;
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPoint = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(this->_fixedPoint) / ( 1 << _fractionalBit );
}

int		Fixed::toInt( void ) const {
	return this->_fixedPoint >> _fractionalBit;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}
