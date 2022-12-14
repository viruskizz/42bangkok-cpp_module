#include "identify.hpp"

Base::~Base() {}

Base * generate(void) {
	int r = rand();
	if (r % 3 == 0)
		return new A;
	if (r % 3 == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch(const std::exception& e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch( const std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>( p );
		std::cout << "C" << std::endl;
		(void)c;
	} catch(const std::exception& e) {}
}
