
#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

# define RED		"\033[0;31m"
# define RESET		"\033[0m"

class Harl {

public:

	Harl( void );
	static int				getLevel( std::string level );
	static void 			complainFilter( std::string level );
	static std::string		toUppercase( std::string str );

private:

	static void	_debug ( void );
	static void	_info ( void );
	static void	_warning ( void );
	static void	_error ( void );

}; 

#endif
