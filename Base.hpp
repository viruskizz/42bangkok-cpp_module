#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

class Base {

protected:

	std::string	_name;

public:

	Base(void);
	Base(std::string name);
	Base(Base const & src);
	~Base(void);

	Base & operator=(Base const & rhs);


	std::string	getName(void) const;

};

std::ostream & operator<<( std::ostream & o, Base const & rhs);

#endif
