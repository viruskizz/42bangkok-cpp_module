#include "PmergeMe.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
PmergeMe::PmergeMe(): _input("") {
	throw PmergeMe::ErrorException();
};

PmergeMe::PmergeMe(std::string name): _input(name){
	
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
	std::cout << "~Deconstructor~" << std::endl;
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
	o << rhs.getInput();
	return o;
}

std::ostream & operator<<( std::ostream & o, std::vector<int> const & rhs ) {
	int i = 0;
	for (int i = 0; i < 5; i++) {
		o << rhs[i] << " ";
	}
	if (rhs.size() > 5)
		o << "[...]";
	return o;
}

std::ostream & operator<<( std::ostream & o, std::deque<int> const & rhs ) {
	int i = 0;
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
}

void	PmergeMe::_addDck(std::string s) {

}