#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc == 1)
		return (std::cout << "need file name as argument" << std::endl, 1);
	try
	{
		BitcoinExchange btc = BitcoinExchange();
		// std::cout << btc.getData() << std::endl;
		btc.exchange("input.txt");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
