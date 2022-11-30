
#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

public:

	Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const &src );
	~Fixed( void );

	Fixed &	operator= ( Fixed const & rhs );
	Fixed	operator+ ( Fixed const & rhs ) const;
	Fixed	operator- ( Fixed const & rhs ) const;
	Fixed	operator* ( Fixed const & rhs ) const;
	Fixed	operator/ ( Fixed const & rhs ) const;

	Fixed &	operator++ ( void );
	Fixed	operator++ ( int );
	Fixed &	operator-- ( void );
	Fixed	operator-- ( int );

	bool	operator> ( Fixed const & rhs ) const;
	bool	operator< ( Fixed const & rhs ) const;
	bool	operator>= ( Fixed const & rhs ) const;
	bool	operator<= ( Fixed const & rhs ) const;
	bool	operator== ( Fixed const & rhs ) const;
	bool	operator!= ( Fixed const & rhs ) const;

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	static const Fixed &	min(Fixed const &a, Fixed const &b);
	static const Fixed &	max(Fixed const &a, Fixed const &b);
	static Fixed &			min(Fixed &a, Fixed &b);
	static Fixed &			max(Fixed &a, Fixed &b);

private:

	int	_fixedPoint;
	static const int _fractionalBit = 8;
}; 

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif
