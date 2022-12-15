#include "Span.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
Span::Span(unsigned int n): _n(n) {}

Span::Span( const Span& src ) {
	*this = src;
}

Span& Span::operator=( Span const &rhs ) {
	if ( this != &rhs ) {
		this->_n = rhs._n;
		this->_v = rhs._v;
	}
	return *this;
}

Span::~Span() {}

unsigned int		Span::getN(void) const {
	return this->_n;
}

std::vector<int>	Span::getV(void) const {
	return this->_v;
}


std::ostream & operator<<( std::ostream & o, Span const & rhs) {
	std::vector<int>::iterator it;
	o << "[";
	for (size_t i = 0 ; i < rhs.getV().size(); ++i)
	{
		o << rhs.getV()[i];
		if (i < rhs.getV().size() - 1)
			o << ", ";
	}
	o << "]";
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
void	Span::addNumber(int x) {
	if (this->_v.size() < this->_n)
		this->_v.push_back(x);
	else
		throw std::out_of_range("out of range");
}

void	Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator  it_end) {
	if (this->_v.size() >= this->_n)
		throw std::out_of_range("out of range");
	std::vector<int>::iterator it;
	it = this->_v.end();
	this->_v.insert(it, it_begin, it_end - this->_v.size() + 1);
}

unsigned int	Span::shortestSpan() {
	if (this->_v.size() < 2)
		throw std::out_of_range("out of range");
	unsigned int span = UINT_MAX;
	for (size_t i = 1 ; i < this->_v.size(); ++i)
	{
		unsigned int dif = abs(this->_v[i] - this->_v[i - 1]);
		if (dif < span)
			span = dif;
	}
	return span;
}

unsigned int	Span::longestSpan() {
	if (this->_v.size() < 2)
		throw std::out_of_range("out of range");
	unsigned int span = 0;
	for (size_t i = 1 ; i < this->_v.size(); ++i)
	{
		unsigned int dif = abs(this->_v[i] - this->_v[i - 1]);
		if (dif > span)
			span = dif;
	}
	return span;
}
