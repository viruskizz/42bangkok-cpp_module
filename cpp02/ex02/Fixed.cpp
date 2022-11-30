#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPoint( 0 ) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const n ) : _fixedPoint( n << _fractionalBit ) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const n ) : _fixedPoint( std::roundf( n * ( 1 << _fractionalBit )) ) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _fixedPoint( 0 ) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {
	// std::cout << "Copy assignment operator called" << std::endl;
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


Fixed	Fixed::operator+( const Fixed &rhs ) const {
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed	Fixed::operator-( const Fixed &rhs ) const {
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed	Fixed::operator*( const Fixed &rhs ) const {
	return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed	Fixed::operator/( const Fixed &rhs ) const {
	return Fixed( this->toFloat() / rhs.toFloat() );
}

Fixed &	Fixed::operator++( void ) {
	this->_fixedPoint += 1;
	return *this;
}

Fixed   Fixed::operator++( int ) {
    Fixed tmp( *this );
    tmp._fixedPoint = this->_fixedPoint;
    this->_fixedPoint += 1;
    return tmp;
}

Fixed& Fixed::operator--( void ) {
    this->_fixedPoint -= 1;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed tmp( *this );
    tmp._fixedPoint = this->_fixedPoint;
	this->_fixedPoint -= 1;
    return tmp;
}

bool    Fixed::operator>( const Fixed &rhs ) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<( const Fixed &rhs ) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=( const Fixed &rhs ) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=( const Fixed &rhs ) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==( const Fixed &rhs ) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=( const Fixed &rhs ) const {
    return this->getRawBits() != rhs.getRawBits();
}

Fixed & Fixed::min( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed & Fixed::min( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed & Fixed::max( Fixed &a, Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed & Fixed::max( const Fixed &a, const Fixed &b ) {
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}