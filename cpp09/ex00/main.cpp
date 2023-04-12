#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc == 1)
		return (std::cout << "need file name as argument" << std::endl, 1);
	try
	{
		BitcoinExchange btc = BitcoinExchange(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
