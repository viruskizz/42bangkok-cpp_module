#include <iostream>
#include <cstdlib>
#include "iter.hpp"

int main() {
	int iarr[5] = {1, 2, 3, 4, 5};
	float farr[3] = {1.1f, 5.5f, 44.0f};
	float darr[2] = {99.9, 10.1};
	::iter(iarr, 5, &myprint);
	::iter(farr, 3, &myprint);
	::iter(darr, 2, &myprint);
}
