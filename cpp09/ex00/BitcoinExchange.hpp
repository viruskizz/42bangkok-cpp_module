#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <istream>

class BitcoinExchange {

private:

	std::string						_filedata;
	std::string						_fileinput;
	std::map<std::string, float>	_data;

	void		_addData(std::string & s);
	void		_cal(std::string & line);
	void		_execfile(std::string &, void (BitcoinExchange::*)(std::string &));

public:

	BitcoinExchange(void);
	BitcoinExchange(std::string name);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange(void);

	BitcoinExchange & operator=(BitcoinExchange const & rhs);


	void							exchange(std::string);

	std::string						const getFiledata() const;
	std::map<std::string, float>	const getData() const;
	float							getValue(std::string) const;

	class ReadFileException: public std::exception {
		public:
			virtual const char* what() const throw() { return "read file error execption!."; }
	};
};

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & rhs);
std::ostream & operator<<( std::ostream & o, std::map<std::string, float> const & rhs);