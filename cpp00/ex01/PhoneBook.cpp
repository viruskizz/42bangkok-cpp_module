#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void) {
}

PhoneBook::~PhoneBook(void) {
	this->_list.clear();
}

int PhoneBook::getMaxSize(void) {
	return SIZE;
}

void PhoneBook::display_add(void) {
	Contact	contact;

	if (contact.formContact()) {
		if (this->_list.size() == SIZE)
			this->_list.pop_back();
		this->_list.insert(this->_list.begin(), contact);
	}
}

void PhoneBook::display_search(void) {
	if (!this->_list.empty()) {
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
	const int width = 10;
	int i = 0;
	std::vector<Contact>::iterator cnt;
	for (cnt = this->_list.begin(); cnt < this->_list.end(); cnt++, i++) {
		std::cout << "| " << (i + 1) << " | ";
		std::cout.width(width);
		std::cout << std::right << this->_limit_word(cnt->fname, width);
		std::cout << " | ";
		std::cout.width(width);
		std::cout << std::right << this->_limit_word(cnt->lname, width);
		std::cout << " | ";
		std::cout.width(width);
		std::cout << std::right << this->_limit_word(cnt->nname, width);
		std::cout << " | ";
		std::cout << std::endl;
	}
}

void PhoneBook::_search_contact()
{
	size_t			idx;
	std::string	input;

	std::cout << "SELECT (1-" << this->_list.size() << ") or 0 to cancel: ";
	std::getline(std::cin, input);
	// idx = std::stoi(input);
	std::istringstream(input) >> idx;
	if (idx == 0) {
		return ;
	} else if (idx > this->_list.size()) {
		std::cout << RED << "Out of range" << RESET << std::endl;
		this->_search_contact();
	} else {
		this->_list.at(idx - 1).showInformation();
	}
}

std::string PhoneBook::_limit_word(std::string word, size_t size) {
	std::string tmp;

	if (word.length() <= size) {
		tmp = word;
	} else {
		tmp = word.substr(0, size - 1);
		tmp += ".";
	}
	return tmp;
}
