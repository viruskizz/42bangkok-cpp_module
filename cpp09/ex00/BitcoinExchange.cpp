#include "BitcoinExchange.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/
BitcoinExchange::BitcoinExchange(): _name("") {
	std::cout << "Default constructor overload" << std::endl;
	std::cout << "" << std::endl;
};

BitcoinExchange::BitcoinExchange(std::string name): _name(name){
	std::cout << "Argument constructor overload" << std::endl;
};

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	std::cout << "Copy constructor overload" << std::endl;
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
		
	this->_name = rhs._name;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "~Deconstructor~" << std::endl;
}

std::string	BitcoinExchange::getName() const {
	return this->_name;
}

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & rhs ) {
	o << rhs.getName();
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/
