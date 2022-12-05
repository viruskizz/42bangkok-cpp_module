#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>

class Brain {

public:

	Brain(void);
	Brain(Brain const & src);
	~Brain(void);

	Brain &	operator=(Brain const & rhs);

private:

	std::string	_ideas[100];

};

#endif