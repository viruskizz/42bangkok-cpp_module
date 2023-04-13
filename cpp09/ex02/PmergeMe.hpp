#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>

class PmergeMe {

protected:

	std::string			_input;
	std::vector<int>	_vtr;
	std::deque<int>		_dck;

	void				_addDck(std::string);
	void				_addVtr(std::string);

public:

	PmergeMe(void);
	PmergeMe(std::string input);
	PmergeMe(PmergeMe const & src);
	~PmergeMe(void);

	PmergeMe & operator=(PmergeMe const & rhs);


	std::string			getInput(void) const;
	std::vector<int>	getVtr(void) const;
	std::deque<int>		getDck(void) const;

	class ErrorException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Error"; }
	};

};

std::ostream & operator<<( std::ostream & o, PmergeMe const & rhs);
std::ostream & operator<<( std::ostream & o, std::vector<int> const & rhs );
std::ostream & operator<<( std::ostream & o, std::deque<int> const & rhs );