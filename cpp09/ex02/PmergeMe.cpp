#include "PmergeMe.hpp"

bool	const isNumber(std::string & s);
void	mergeSort(int arr[], int l, int r);
void	merge(int arr[], int p, int q, int r);

template<typename T>
void tmerge(T arr, int p, int q, int r) ;
template<typename T>
void tmergeSort(T arr, int l, int r);

/************************************************
 * Setup default construct and  member function *
 ************************************************/
PmergeMe::PmergeMe(): _input("") {
	throw PmergeMe::ErrorException();
};

PmergeMe::PmergeMe(std::string input): _input(input) {
	this->_addNumbers(input);
};

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
	this->_input = rhs._input;
	this->_vtr = rhs._vtr;
	this->_dck = rhs._dck;
	return *this;
}

PmergeMe::~PmergeMe() {
}

std::string	PmergeMe::getInput() const {
	return this->_input;
}

std::vector<int>	PmergeMe::getVtr(void) const {
	return this->_vtr;
}

std::deque<int>		PmergeMe::getDck(void) const {
	return this->_dck;
}

std::ostream & operator<<( std::ostream & o, PmergeMe const & rhs ) {
	int i = 0;
	int sp = 0;
	std::string s = rhs.getInput();
	while (s.c_str()[i] != '\0') {
		if (s.at(i) == ' ')
			sp++;
		if (sp == 5) {
			o << " [...]";
			break;
		}
		o << s.at(i++);
	}
	return o;
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


void	PmergeMe::_addNumbers(std::string &s) {
	std::size_t start = 0;
	std::size_t end = s.find(" ");
	while (end != std::string::npos) {
		std::string num = s.substr(start, end - start);
		if (!isNumber(num))
			throw PmergeMe::ErrorException();
		this->_dck.push_back(atoi(num.c_str()));
		this->_vtr.push_back(atoi(num.c_str()));
		start = end + 1;
		end = s.find(" ", start);
	}
	std::string num = s.substr(start, end - start);
	if (!isNumber(num))
		throw PmergeMe::ErrorException();
	this->_dck.push_back(atoi(num.c_str()));
	this->_vtr.push_back(atoi(num.c_str()));
}


void	PmergeMe::sortVtr() {
	clock_t t = clock();
	tmergeSort(this->_vtr, 0, this->_vtr.size() - 1);
	this->_dif1 = ((double) (clock() - t)) / CLOCKS_PER_SEC;
	std::cout << "Vector-Sorted: " << this->_vtr << std::endl;
}

void	PmergeMe::sortDck() {
	clock_t t = clock();
	tmergeSort(this->_dck, 0, this->_dck.size() - 1);
	this->_dif2 = ((double) (clock() - t)) / CLOCKS_PER_SEC;
	std::cout << "Deque-Sorted: " << this->_dck << std::endl;
}

void	PmergeMe::printVtrResult(void) const {
	std::cout.precision(6);
	std::cout << "Time to process a range of ";
	std::cout << this->_vtr.size();
	std::cout << " elements with std::vector : ";
	std::cout << std::fixed << this->_dif1;
	std::cout << " s" << std::endl;
}

void	PmergeMe::printDckResult(void) const {
	std::cout.precision(6);
	std::cout << "Time to process a range of ";
	std::cout << this->_dck.size();
	std::cout << " elements with std::deque  : ";
	std::cout << std::fixed << this->_dif2;
	std::cout << " s" << std::endl;
}

/*
 * Utility
 */

bool	const isNumber(std::string & s) {
	for (int i = 0; i < (int) s.length(); i++) {
		if (!isdigit(s.at(i)))
			return false;
	}
	return true;
}

template<typename T>
void tmergeSort(T arr, int l, int r) {
	if (l < r) {
		// m is the point where the array is divided into two subarrays
		int m = l + (r - l) / 2;
		tmergeSort(arr, l, m);
		tmergeSort(arr, m + 1, r);
		// Merge the sorted subarrays
		tmerge(arr, l, m, r);
	}
}

template<typename T>
void tmerge(T arr, int p, int q, int r) {
	// Create L ← A[p..q] and M ← A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;	
	int L[n1], M[n2];	
	for (int i = 0; i < n1; i++)
	  L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
	  M[j] = arr[q + 1 + j];	
	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;	
	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}	
	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1) {
	  arr[k++] = L[i++];
	}
	while (j < n2) {
		arr[k++] = M[j++];
	}
}
