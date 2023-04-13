#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <deque>
#include <unistd.h>

class PmergeMe {

private:

	std::string			_input;
	std::vector<int>	_vtr;
	std::deque<int>		_dck;
	double				_dif1;
	double				_dif2;

	void				_addVtr(std::string);
	void				_addDck(std::string);


public:

	PmergeMe(void);
	PmergeMe(std::string input);
	PmergeMe(PmergeMe const & src);
	~PmergeMe(void);

	PmergeMe & operator=(PmergeMe const & rhs);


	std::string			getInput(void) const;
	std::vector<int>	getVtr(void) const;
	std::deque<int>		getDck(void) const;

	void				sortVtr(void);
	void				sortDck(void);
	void				printVtrResult(void);
	void				printDckResult(void);

	class ErrorException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Error"; }
	};

};

std::ostream & operator<<( std::ostream & o, PmergeMe const & rhs);
std::ostream & operator<<( std::ostream & o, std::vector<int> const & rhs );
std::ostream & operator<<( std::ostream & o, std::deque<int> const & rhs );