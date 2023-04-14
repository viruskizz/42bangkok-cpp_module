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
	this->_stk = rhs._stk;
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
std::stack<int>	RPN::getStk() const {
	return this->_stk;
}
std::ostream & operator<<( std::ostream & o, RPN const & rhs ) {
	o << rhs.getInput();
	return o;
}
std::ostream & operator<<( std::ostream & o, std::stack<int> const & rhs ) {
	std::stack<int> tmp = rhs;
	o << "{";
	while (!tmp.empty()) {
		o << tmp.top();
		if (tmp.size() != 1)
			o << " , ";
		tmp.pop();
	}
	o << "}";
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
const char *OPT = "+-*/";
void	RPN::_cal() {
	for (int i = 0; i < (int) this->_input.length(); i += 2) {
		char c = this->_input[i];
		char nc = this->_input[i + 1];
		if (!isdigit(c) && !strchr(OPT, c))
			throw RPN::ErrorException();
		if (nc != ' ' && nc != '\0')
			throw RPN::ErrorException();
		if (isdigit(c))
			this->_stk.push(c - '0');
		if (strchr(OPT, c)) {
			int sum;
			int a = this->_stk.top();
			this->_stk.pop();
			int b = this->_stk.top();
			this->_stk.pop();
			if (c == '+')
				sum = b + a;
			else if (c == '-')
				sum = b - a;
			else if (c == '*')
				sum = b * a;
			else if (c == '/')
				sum = b / a;
			// std::cout << "sum = " << sum << std::endl;
			this->_stk.push(sum);
		}
		// std::cout << this->_stk << std::endl;
	}
	this->_result = this->_stk.top();
}
