#include "Harl.hpp"

Harl::Harl() {}

std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
void	Harl::complainFilter( std::string level ) {
	int	startLevel = getLevel(level);

	if (startLevel < 0)
	{
		std::cerr << RED << "[ NO this log level ]" << RESET << std::endl;
		return ;
	}
	for (int i = startLevel; i < maxLevel; i++) {
		std::cout << "[" << levels[i] << "]" << std::endl;
		fnc[i]();
	}
}

int	Harl::getLevel( std::string level ) {
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
	std::cout << msg << std::endl;
}

void	Harl::_info ( void ) {
	std::string msg = "1 > I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << msg << std::endl;
}

void	Harl::_warning ( void ) {
	std::string msg = "2 > I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month";
	std::cout << msg << std::endl;
}

void	Harl::_error ( void ) {
	std::string msg = "3 > This is unacceptable! I want to speak to the manager now";
	std::cout << msg << std::endl;
}

int			Harl::maxLevel		 = 4;
void		(*Harl::fnc[])(void) = {_debug, _info, _warning, _error};
std::string	Harl::levels[]		 = {"DEBUG", "INFO", "WARNING", "ERROR"};
