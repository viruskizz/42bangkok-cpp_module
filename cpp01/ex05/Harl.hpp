
#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

class Harl {

public:

	Harl( void );
	static void 		complain( std::string level );
	static std::string	toUppercase( std::string str );

private:

	static void	_debug ( void );
	static void	_info ( void );
	static void	_warning ( void );
	static void	_error ( void );

}; 

#endif
