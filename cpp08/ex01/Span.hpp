#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits> 
#include <exception>

class Span {

private:
	unsigned int		_n;
	std::vector<int>	_v;

	Span( void );

public:
	Span(unsigned int n);
	
	Span(const Span& src);
	~Span(void);

	Span&	operator=(const Span& rhs);

	unsigned int 		getN(void) const;
	std::vector<int>	getV(void) const;

	void				addNumber(int);
	void 				addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
	unsigned int		shortestSpan(void);
	unsigned int		longestSpan(void);
};

std::ostream & operator<<( std::ostream & o, Span const & rhs);
