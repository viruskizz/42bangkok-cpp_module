#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <climits>
#include <cfloat>

#define	CHAR	1
#define	INT		2
#define	FLOAT	3
#define	DOUBLE	4

class Convert {

private:

	std::string	_input;

public:

	Convert(std::string input);
	Convert(Convert const & src);
	~Convert(void);

	Convert & operator=(Convert const & rhs);

	std::string		getInput(void) const;

	static bool			isLiteral(std::string const s, int type);
	static std::string	to_string(double d);

	void			printCIDF(void);
	void			printChar(void);
	void			printInt(void);
	void			printDouble(void);
	void			printFloat(void);
};



// std::ostream & operator<<( std::ostream & o, Convert const & rhs);

#endif
