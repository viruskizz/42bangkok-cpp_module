#include "Harl.hpp"

Harl::Harl() {}

void	Harl::complainFilter( std::string level ) {
	int	startLevel = getLevel(level);

	switch (startLevel)
	{
		case 0:
			Harl::_debug();
		case 1:
			Harl::_info();
		case 2:
			Harl::_warning();
		case 3:
			Harl::_error();
			break;
		default:
			std::cerr << RED << "[ NO this log level ]" << RESET << std::endl;
	}
}

int	Harl::getLevel( std::string level ) {
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if ( Harl::toUppercase(level).compare(levels[i]) == 0 )
			return i;
	}
	return -1;
}

std::string	Harl::toUppercase( std::string str ) {
	std::string s;
	for ( std::string::iterator it = str.begin(); it != str.end(); ++it)
		s += std::toupper(*it);
	return s;
}

void	Harl::_debug ( void ) {
	std::string msg = "0 > love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!";
	std::cout << "[DEBUG]\n" << msg << "\n" << std::endl;
}

void	Harl::_info ( void ) {
	std::string msg = "1 > I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << "[INFO]\n" << msg << "\n" << std::endl;
}

void	Harl::_warning ( void ) {
	std::string msg = "2 > I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month";
	std::cout << "[WARNING]\n" << msg << "\n" << std::endl;
}

void	Harl::_error ( void ) {
	std::string msg = "3 > This is unacceptable! I want to speak to the manager now";
	std::cout << "[ERROR]\n" << msg << "\n" << std::endl;
}


