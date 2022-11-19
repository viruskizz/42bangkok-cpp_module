#ifndef CONTACT_H
# define CONTACT_H
#include <string>


# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define GBOLD		"\033[1;37m"
# define RESET		"\033[0m"

class Contact {

public:

	std::string fname;
	std::string lname;
	std::string nname;
	std::string tel;
	std::string secret;

	Contact(void);

	void	showInformation( void );
	bool	formContact( void );
};

#endif
