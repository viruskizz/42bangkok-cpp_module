#include "PmergeMe.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
PmergeMe::PmergeMe(): _input("") {
	throw PmergeMe::ErrorException();
};

PmergeMe::PmergeMe(std::string name): _input(name) {
	
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
	// o << rhs.getInput();
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
void	PmergeMe::_addVtr(std::string s) {
	std::size_t pos = s.find("live");
	(void) pos;
}

void	PmergeMe::_addDck(std::string s) {
	std::size_t pos = s.find("live");
	(void) pos;
}

void	PmergeMe::sortVtr() {
	clock_t t = clock();
	usleep(200);
	this->_dif1 = ((double) (clock() - t)) / CLOCKS_PER_SEC;
}
void	PmergeMe::sortDck() {
	clock_t t = clock();
	usleep(200);
	this->_dif2 = ((double) (clock() - t)) / CLOCKS_PER_SEC;
}

void	PmergeMe::printVtrResult(void) {
	std::cout.precision(6);
	std::cout << "Time to process a range of ";
	std::cout << this->_vtr.size();
	std::cout << " elements with std::vector : ";
	std::cout << std::fixed << this->_dif1;
	std::cout << " s" << std::endl;
}
void	PmergeMe::printDckResult(void) {
	std::cout.precision(6);
	std::cout << "Time to process a range of ";
	std::cout << this->_dck.size();
	std::cout << " elements with std::deque  : ";
	std::cout << std::fixed << this->_dif2;
	std::cout << " s" << std::endl;
}
