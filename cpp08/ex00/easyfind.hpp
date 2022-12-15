#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>


class NotFoundException : public std::exception {
public:
	const char* what() const throw() {
		return "Not found element";
	}
};

template<typename T>
int easyfind(T & container, int f) {
	std::vector<int>::iterator it;
	it = std::find(container.begin(), container.end(), f);
	if (it != container.end())
	// if (std::find(container.begin(), container.end(), f) != container.end())
		return f;
	else
		throw NotFoundException(); 
}

std::ostream & operator<<(std::ostream & o, std::vector<int> const & rhs) {
	std::vector<int>::iterator it;
	o << "[";
	for (size_t i = 0 ; i < rhs.size(); ++i)
	{
		o << rhs[i];
		if (i < rhs.size() - 1)
			o << ", ";
	}
	o << "]";
	return o;
};
