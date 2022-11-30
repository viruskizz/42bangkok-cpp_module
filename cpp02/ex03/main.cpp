#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point a = Point();
	Point b = Point(10.0f, 30.0f);
	Point c = Point(20, 0);
	Point p = Point(5, 10);
	Point o = Point(0, 10);
	Point e = Point(0, 0);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << "in = " << bsp(a, b, c, p) << std::endl;
	std::cout << "out = " << bsp(a, b, c, o) << std::endl;
	std::cout << "edge = " << bsp(a, b, c, e) << std::endl;
	return 0;
}
