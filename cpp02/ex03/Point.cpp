#include "Point.hpp"

Point::Point( void ): _x(Fixed(0)), _y(Fixed(0)) {}

Point::~Point( void ) {}

Point::Point( float const x, float const y ): _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point( Point const & p ) {
	this->_x = p._x;
	this->_y = p._y;
}

Point &	Point::operator=( Point const & rhs ) {
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

Fixed	Point::getPointX( void ) const {
	return this->_x;
}

Fixed	Point::getPointY( void ) const {
	return this->_y;
}

std::ostream & operator<<( std::ostream & o, Point const & p ) {
	o << "(" << p.getPointX().toFloat() << "," << p.getPointY().toFloat() << ")";
	return o;
}
