
#ifndef POINT_H
# define POINT_H

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point {

public:

	Point( void );
	Point( float const x, float const y );
	Point( Point const & p );
	~Point ( void );

	Point &	operator= ( Point const & rhs );

	Fixed	getPointX( void ) const;
	Fixed	getPointY( void ) const;


private:

	Fixed	_x;
	Fixed	_y;

}; 

std::ostream & operator<<( std::ostream & o, Point const & p );

bool	bsp(Point const a, Point const b, Point const c, Point const point);
Fixed	triangle_area(Point const a, Point const b, Point const c);
Fixed	abs(Fixed f);
bool	sameline(Point const a, Point const b, Point const p);

#endif
