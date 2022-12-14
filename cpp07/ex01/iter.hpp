#ifndef ITER_H
#define ITER_H

#include <cstddef>

template<typename T>
void iter(T *arr, size_t const & n, void (*f)(T &)) {
	for (size_t i = 0; i < n; i++)
		f(arr[i]);
}

template<typename T>
void	myprint(T & x) {
	std::cout << x << std::endl;
}

#endif