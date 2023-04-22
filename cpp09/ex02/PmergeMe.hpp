#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <vector>
#include <deque>
#include <unistd.h>
#include <cstdlib>

class PmergeMe {

private:

	std::vector<int>	_vtr;
	std::deque<int>		_dck;
	double				_dif1;
	double				_dif2;

	void				_addNumbers(std::string &);
	void				_addNumbers(char **argv);

public:

	PmergeMe(void);
	PmergeMe(int, char **);
	PmergeMe(PmergeMe const &);
	~PmergeMe(void);

	PmergeMe & operator=(PmergeMe const & rhs);


	std::vector<int>	getVtr(void) const;
	std::deque<int>		getDck(void) const;

	void				sortVtr(void);
	void				sortDck(void);
	void				printVtrResult(void) const;
	void				printDckResult(void) const;

	class ErrorException: public std::exception {
		public:
			virtual const char* what() const throw() { return "Error"; }
	};

};

std::ostream & operator<<( std::ostream & o, PmergeMe const & rhs);
std::ostream & operator<<( std::ostream & o, std::vector<int> const & rhs );
std::ostream & operator<<( std::ostream & o, std::deque<int> const & rhs );