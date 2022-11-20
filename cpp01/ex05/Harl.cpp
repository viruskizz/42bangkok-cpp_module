#include "Harl.hpp"

Harl::Harl() {}

void	Harl::complain( std::string level ) {
	std::string	fncName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (*fnc[4])(void) = {_debug, _info, _warning, _error};
	for (int i = 0; i < 4; i++) {
		if ( Harl::toUppercase(level).compare(fncName[i]) == 0 )
			fnc[i]();
	}
}

std::string	Harl::toUppercase( std::string str ) {
	std::string s;
	for ( std::string::iterator it = str.begin(); it != str.end(); ++it)
		s += std::toupper(*it);
	return s;
}

void	Harl::_debug ( void ) {
	std::string msg = "[DEBUG] love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!";
	std::cout << msg << std::endl;
}
void	Harl::_info ( void ) {
	std::string msg = "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << msg << std::endl;
}
void	Harl::_warning ( void ) {
	std::string msg = "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month";
	std::cout << msg << std::endl;
}
void	Harl::_error ( void ) {
	std::string msg = "[ERROR] This is unacceptable! I want to speak to the manager now";
	std::cout << msg << std::endl;
}
