#pragma once
// https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators
#include <iostream>
#include <stack>
#include <deque>

template< typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {

using std::stack<T, Container>::c;

public:

	MutantStack(void) {};
	MutantStack(const MutantStack& rhs) { *this = rhs; }
	~MutantStack(void) {};

	MutantStack&	operator=(const MutantStack& rhs) {
		std::stack<T, Container>::operator=(rhs);
		return *this;
	}
	typedef typename Container::iterator	iterator;

	iterator	begin() { return this->c.begin(); }
	iterator	end() { return this->c.end(); }
};
