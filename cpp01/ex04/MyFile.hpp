
#ifndef MY_FILE_H
# define MY_FILE_H

# include <iostream>
# include <fstream>
# include <string>

# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define RESET	"\033[0m"

class MyFile {

public:

	// static std::fstream	ifs;
	MyFile( std::string name);
	~MyFile();

	static std::string	read (std::string name);
	static void			write ( std::string data, std::string filename );
	static void			cat ( std::string filename );
	static std::string	str_repleace (std::string str, std::string s1, std::string s2);

	void				cat ( void );
	std::string			sed( std::string s1, std::string s2);

	std::string			getData();
	std::string			getName();

private:

	std::string	_name;
	std::string	_data;

};

#endif
