#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H

#include <iostream>
#include <string>

class BitcoinExchange {

protected:

	std::string	_name;

public:

	BitcoinExchange(void);
	BitcoinExchange(std::string name);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange(void);

	BitcoinExchange & operator=(BitcoinExchange const & rhs);


	std::string	getName(void) const;

};

std::ostream & operator<<( std::ostream & o, BitcoinExchange const & rhs);

#endif
