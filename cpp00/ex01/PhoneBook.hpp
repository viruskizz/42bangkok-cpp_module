#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <iostream>
# include <sstream>
# include <vector>
# include <string>
# include <algorithm>
# include "Contact.hpp"

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

# define SIZE		8

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void		display_add(void);
	void		display_search(void);
	int			getMaxSize(void);

private:

	std::vector<Contact>	_list;

	void		_print_head_table(void);
	void		_print_body_table();
	void		_search_contact();
	std::string	_limit_word(std::string word, size_t size);

};

#endif
