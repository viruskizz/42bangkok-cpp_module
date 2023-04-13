#include "RPN.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
RPN::RPN(): _input(""), _result(0) {
	throw RPN::ErrorException();
};

RPN::RPN(std::string input): _input(input), _result(0) {
	this->_cal();
};

RPN::RPN(RPN const & src) {
	*this = src;
}

RPN & RPN::operator=(RPN const & rhs) {
	if (this == &rhs)
		return *this;
	this->_input = rhs._input;
	this->_result = rhs._result;
	this->_deck = rhs._deck;
	return *this;
}

RPN::~RPN() {
}

std::string	RPN::getInput() const {
	return this->_input;
}
int	RPN::getResult() const {
	return this->_result;
}
std::deque<int>	RPN::getDeck() const {
	return this->_deck;
}
std::ostream & operator<<( std::ostream & o, RPN const & rhs ) {
	o << rhs.getInput();
	return o;
}
std::ostream & operator<<( std::ostream & o, std::deque<int> const & rhs ) {
	o << "{";
	for(std::deque<int>::const_iterator  it = rhs.cbegin(); it != rhs.cend(); it++)
		if ((it + 1) != rhs.cend()) 
			o << *it << ", ";
		else
			o << *it;
	o << "}";
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
const char *OPT = "+-*/";
void	RPN::_cal() {
	for (int i = 0; i < this->_input.length(); ++i) {
		char c = this->_input[i];
		char nc = this->_input[i + 1];
		if (!isdigit(c) && !strchr(OPT, c))
			throw RPN::ErrorException();
		if (nc != ' ' && nc != '\0')
			throw RPN::ErrorException();
		if (isdigit(c))
			this->_deck.push_back(c - '0');
		std::cout << this->_deck << std::endl;
		++i;
	}
}
