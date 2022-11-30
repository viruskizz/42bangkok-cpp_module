#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void) {
	this->_size = 0;
}

PhoneBook::~PhoneBook(void) {
}

int PhoneBook::getMaxSize(void) {
	return MAX_SIZE;
}

void PhoneBook::display_add(void) {
	Contact	contact;

	if (contact.formContact()) {
		if (this->_size > 0)
			this->_rearrange();
		this->_list[0] = contact;
		if (this->_size < MAX_SIZE)
			this->_size += 1;
	}
}

void PhoneBook::display_search(void) {
	if (this->_size > 0) {
		this->_print_head_table();
		this->_print_body_table();
		this->_search_contact();
	} else {
		std::cout << RED << "NO Contact" << RESET << std::endl;
	}
}

void PhoneBook::_print_head_table(void) {
	std::cout << CYAN;
	std::cout << "| i |";
	std::cout << "  firstname |" << "  lastname  |" << "  nickname  |" << std::endl;
	std::cout.width(44);
	std::cout.fill('-');
	std::cout << "" << std::endl;
	std::cout << RESET;
	std::cout.fill(' ');
	std::cout.width();
}

void PhoneBook::_print_body_table() {
	const int	width = 10;
	Contact		cnt;
	
	for (int i = 0; i < this->_size; i++) {
		cnt = this->_list[i];
		std::cout << "| " << (i + 1) << " | ";
		std::cout.width(width);
		std::cout << std::right << this->_limit_word(cnt.fname, width);
		std::cout << " | ";
		std::cout.width(width);
		std::cout << std::right << this->_limit_word(cnt.lname, width);
		std::cout << " | ";
		std::cout.width(width);
		std::cout << std::right << this->_limit_word(cnt.nname, width);
		std::cout << " | ";
		std::cout << std::endl;
	}
}

void PhoneBook::_search_contact() {
	int			idx;
	std::string	input;

	std::cout << "SELECT (1-" << this->_size << ") or 0 to cancel: ";
	if (!std::getline(std::cin, input)) {
		return;
	}
	std::istringstream(input) >> idx;
	if (idx <= 0) {
		return;
	} else if (idx > this->_size) {
		std::cout << RED << "Out of range" << RESET << std::endl;
		this->_search_contact();
	} else {
		this->_list[idx - 1].showInformation();
	}
}

void PhoneBook::_rearrange() {
	for (int i = MAX_SIZE - 1; i > 0; i--) {
		if (!this->_list[i - 1].fname.empty())
			this->_list[i] = this->_list[i - 1];
	}
}

std::string PhoneBook::_limit_word(std::string word, size_t size) {
	std::string	tmp;

	if (word.length() <= size) {
		tmp = word;
	} else {
		tmp = word.substr(0, size - 1);
		tmp += ".";
	}
	return tmp;
}
