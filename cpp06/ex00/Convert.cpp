#include "Convert.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
Convert::Convert(std::string input): _input(input) {}

Convert::Convert(Convert const & src) {
	*this = src;
}

Convert & Convert::operator=(Convert const & rhs) {
	if (this == &rhs)
		return *this;
	this->_input = rhs._input;
	return *this;
}
Convert::~Convert() {}

std::string	Convert::getInput() const {
	return this->_input;
}

/************************************************
 *           Specific member function           *
 ************************************************/
std::string	Convert::to_string(double d) {
	std::ostringstream s;
	s << d;
	return s.str();
}

bool	Convert::isLiteral(std::string s, int type) {
	switch (type)
	{
	case CHAR:
	case INT:
		if (s == "nan" || s == "-inf" || s == "+inf" || s == "nanf" || s == "-inff" || s == "+inff")
			return true;
		return false;
	case FLOAT:
		if (s == "nanf" || s == "-inff" || s == "+inff")
			return true;
		return false;
	case DOUBLE:
		if (s == "nan" || s == "-inf" || s == "+inf")
			return true;
		return false;
	}
	return false;
}

void	Convert::printCIDF(void) {
	this->printChar();
	this->printInt();
	this->printDouble();
	this->printFloat();
}

void	Convert::printChar(void) {
	int	i;

	std::istringstream(this->_input) >> i;
	if (this->isLiteral(this->_input, CHAR) || i < 0 || i > 128)
		std::cout << "char: imposible"  << std::endl;
	else if (i < 32 || i > 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << (char) i << "'" << std::endl;
}

void	Convert::printInt() {
	double	d;

	std::istringstream(this->_input) >> d;
	if (this->isLiteral(this->_input, INT)
		|| (d == 0 && this->_input != "0")
		|| d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << (int) d << std::endl;
}

void	Convert::printFloat(void) {
	double d;
	std::istringstream(this->_input) >> d;
	if (this->isLiteral(this->_input, DOUBLE))
		this->_input += "f";
	if (this->isLiteral(this->_input, FLOAT))
		std::cout << "float: " << this->getInput() << std::endl;
	else if (d != 0 && (d < FLT_MIN || d > FLT_MAX))
		std::cout << "float: impossible" << std::endl;
	else if (to_string(d).find(".") != std::string::npos)
		std::cout << "float: " << (float) d << "f" << std::endl;
	else
		std::cout << "float: " << (float) d << ".0f" << std::endl;
}

void	Convert::printDouble(void) {
	long double dd;
	std::istringstream(this->_input) >> dd;
	if (this->isLiteral(this->_input, DOUBLE))
		std::cout << "double: " << this->getInput() << std::endl;
	else if (dd != 0 && (dd < DBL_MIN || dd > DBL_MAX))
		std::cout << "double: impossible" << std::endl;
	else if (to_string((double) dd).find(".") != std::string::npos)
		std::cout << "double: " << (double) dd << std::endl;
	else
		std::cout << "double: " << (double) dd << ".0" << std::endl;
}
