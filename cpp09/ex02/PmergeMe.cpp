#include "PmergeMe.hpp"

bool	isNumber(char *s);

template<typename T>
void tmerge(T & arr, int start, int mid, int end);

template<typename T>
void tmergeSort(T & arr, int start, int end);

/************************************************
 * Setup default construct and  member function *
 ************************************************/
PmergeMe::PmergeMe() {
	throw PmergeMe::ErrorException();
};

PmergeMe::PmergeMe(int argc, char **argv) {
	argv[argc] = NULL;
	this->_addNumbers(argv + 1);
};

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
	this->_vtr = rhs._vtr;
	this->_dck = rhs._dck;
	return *this;
}

PmergeMe::~PmergeMe() {
}

std::vector<int>	PmergeMe::getVtr(void) const {
	return this->_vtr;
}

std::deque<int>		PmergeMe::getDck(void) const {
	return this->_dck;
}

std::ostream & operator<<( std::ostream & o, std::vector<int> const & rhs ) {
	int n = rhs.size() > 5 ? 5 : rhs.size();
	for (int i = 0; i < n; i++) {
		o << rhs[i] << " ";
	}
	if (rhs.size() > 5)
		o << "[...]";
	return o;
}

std::ostream & operator<<( std::ostream & o, std::deque<int> const & rhs ) {
	for (int i = 0; i < 5; i++) {
		o << rhs[i] << " ";
	}
	if (rhs.size() > 5)
		o << "[...]";
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/

void	PmergeMe::_addNumbers(char **argv) {
	for (int i = 0; argv[i]; i++) {
		if (!isNumber(argv[i]))
			throw PmergeMe::ErrorException();
		int num = atoi(argv[i]);
		if (num < 0)
			throw PmergeMe::ErrorException();
		this->_dck.push_back(num);
		this->_vtr.push_back(num);
	}
}

void	PmergeMe::sortVtr() {
	clock_t t = clock();
	tmergeSort(this->_vtr, 0, this->_vtr.size() - 1);
	this->_dif1 = ((double) (clock() - t)) / CLOCKS_PER_SEC;
}

void	PmergeMe::sortDck() {
	clock_t t = clock();
	tmergeSort(this->_dck, 0, this->_dck.size() - 1);
	this->_dif2 = ((double) (clock() - t)) / CLOCKS_PER_SEC;
}

void	PmergeMe::printVtrResult(void) const {
	std::cout.precision(6);
	std::cout << "Time to process a range of ";
	std::cout << this->_vtr.size();
	std::cout << " elements with std::vector : ";
	std::cout << std::fixed << this->_dif1 * 1000000;
	std::cout << " us" << std::endl;
}

void	PmergeMe::printDckResult(void) const {
	std::cout.precision(6);
	std::cout << "Time to process a range of ";
	std::cout << this->_dck.size();
	std::cout << " elements with std::deque  : ";
	std::cout << std::fixed << this->_dif2 * 1000000;
	std::cout << " us" << std::endl;
}

/*
 * Utility
 */

bool	isNumber(char *s) {
	for (int i = 0; i < (int) strlen(s); i++) {
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

template<typename T>
void tmergeSort(T & arr, int start, int end) {
	if (start < end) {
		// m is the point where the array is divided into two subarrays
		int mid = start + (end - start) / 2;
		tmergeSort(arr, start, mid);
		tmergeSort(arr, mid + 1, end);
		// Merge the sorted subarrays
		tmerge(arr, start, mid, end);
	}
}

template<typename T>
void tmerge(T & arr, int start, int mid, int end) {
	T temp(end - start + 1);
	int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= end) {
		temp[k++] = arr[j++];
	}
	std::copy(temp.begin(), temp.end(), arr.begin() + start);
}