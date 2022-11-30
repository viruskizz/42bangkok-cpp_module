#include "Point.hpp"

/**
 * @brief Fomular
 * https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
 * https://stackoverflow.com/questions/17692922/check-is-a-point-x-y-is-between-two-points-drawn-on-a-straight-line
 * 
 */
bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed abc = triangle_area(a, b, c);
	Fixed pbc = triangle_area(point, b, c);
	Fixed pac = triangle_area(point, a, c);
	Fixed pab = triangle_area(point, a, b);
	if (abc == pbc + pac + pab)
		return (!sameline(a, b, point) && !sameline(b, c, point) && !sameline(a, c, point));
	return false;
}

bool	sameline(Point const a, Point const b, Point const p) {
	Fixed dx = a.getPointX() - b.getPointX();
	Fixed px = p.getPointX() - a.getPointX();
	Fixed dy = a.getPointY() - b.getPointY();
	Fixed py = p.getPointY() - a.getPointY();
	return (py * dx == px * dy);
}


Fixed	triangle_area(Point const a, Point const b, Point const c) {
	Fixed ax = a.getPointX() * (b.getPointY() - c.getPointY());
	Fixed bx = b.getPointX() * (c.getPointY() - a.getPointY());
	Fixed cx = c.getPointX() * (a.getPointY() - b.getPointY());
	Fixed zx = abs(ax + bx + cx);
	return (zx / Fixed(2));
}

Fixed	abs(Fixed f) {
	if (f < Fixed(0))
		f = f * -1;
	return f;
}
