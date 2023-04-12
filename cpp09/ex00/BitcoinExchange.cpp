#include "BitcoinExchange.hpp"

/************************************************
 * Setup default construct and  member function *
 ************************************************/

BitcoinExchange::BitcoinExchange()
{
	throw BitcoinExchange::ReadFileException();
};

BitcoinExchange::BitcoinExchange(std::string name): _fileIn(name){
	this->readfile();
};

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	std::cout << "Copy constructor overload" << std::endl;
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	std::cout << "Assignment constructor overload" << std::endl;
	if (this == &rhs)
		return *this;
		
	this->_fileIn = rhs._fileIn;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "~Deconstructor~" << std::endl;
}

std::string	BitcoinExchange::getName() const {
	return this->_fileIn;
}

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & rhs ) {
	o << rhs.getName();
	return o;
}

/************************************************
 *           Specific member function           *
 ************************************************/

void BitcoinExchange::readfile() const
{
	std::fstream	file;
	std::string		line;
	file.open(this->_fileIn.c_str());
	if (!file)
		throw BitcoinExchange::ReadFileException();
	else
	{
		while (true) {
			if (!std::getline(file, line))
				break;
			std::cout << line << std::endl;
		}
		std::cin.clear();
		file.close();
	}

}
