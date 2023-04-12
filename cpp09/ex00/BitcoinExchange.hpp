#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <istream>

class BitcoinExchange {

private:

	std::map<std::string, float>	_data;
	std::string						_fileIn;
	std::string						_filedata;
	std::string						_fileOut;

	void							readfile() const;
public:

	BitcoinExchange(void);
	BitcoinExchange(std::string name);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange(void);

	BitcoinExchange & operator=(BitcoinExchange const & rhs);


	std::string	getName(void) const;

	class ReadFileException: public std::exception {
		public:
			virtual const char* what() const throw() { return "read file error execption!."; }
	};
};

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & rhs);

