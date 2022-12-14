#pragma once
#include <stdlib.h>
#include <time.h>

template<typename T>
class Array
{
private:
	unsigned int _n;
	T *	_arr;
public:
	Array<T>(void): _n(0), _arr(new T()) {}
	Array<T>(unsigned int n): _n(n), _arr(new T[n]) {}
	Array<T>(Array const & src): _n(src._n), _arr(new T[src._n]) {
		for(unsigned int i = 0; i < this->_n; i++) {
			this->_arr[i] = src._arr[i];
		}
	}
	~Array<T>(void) {
		delete [] this->_arr;
	}

	Array & operator=(T const & rhs) {
		if (this == &rhs)
			return *this;
		delete [] this->_arr;
		this->_n = rhs._n;
		this->_arr = new T[rhs._n];
		for(unsigned int i = 0; i < this->_n; i++) {
			this->_arr[i] = rhs._arr[i];
		}
		return *this;
	}

	T & operator[](unsigned int i) const {
		if (i >= this->_n)
			throw IndexOutOfBound();
		return this->_arr[i];
	}

	unsigned int size(void) const {
		return this->_n;
	}

	class IndexOutOfBound: public std::exception {
		public:
			virtual const char* what() const throw() { return "Index is out of bound"; }
	};
};

template<typename T>
std::ostream & operator<<( std::ostream & o, Array<T> const & rhs) {
	o << "[";
	for (unsigned int i = 0; i < rhs.size(); i++) {
		o << rhs[i];
		if (i < rhs.size() - 1)
			o << ", ";
	}
	o << "]";
	return o;
};
