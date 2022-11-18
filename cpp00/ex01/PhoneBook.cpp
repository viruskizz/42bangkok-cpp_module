#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void) {
	this->_contain = 0;
}

PhoneBook::~PhoneBook(void) {
}

void PhoneBook::display_add(void) {
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	tel;
	std::string	secret;

	std::cout << GREEN << "=New contact=" << RESET << std::endl;
	std::cout << BOLD << "firstname: " << RESET, std::cin >> fname;
	std::cout << BOLD << "lastname: " << RESET, std::cin >> lname;
	std::cout << BOLD << "nickname: " << RESET, std::cin >> nname;
	std::cout << BOLD << "phone: " << RESET, std::cin >> tel;
	std::cout << BOLD << "secret: " << RESET, std::cin >> secret;
	if (fname.empty() || lname.empty() || nname.empty() || tel.empty() || secret.empty()) {
		std::cout << RED << "Fields cannot be empty" << RESET << std::endl;
	} else {
		PhoneBook::_add_contact(fname, lname, nname, tel, secret);
		std::cout << YELLOW << "Contact added" << RESET << std::endl;
	}
}

void PhoneBook::display_search(void) {
	std::string	input;

	std::cout << "Search:";
	std::cin >> input;
	if (!input.empty()) {
		this->_print_head_table();
		this->_print_body_table(input);
	}

}

int PhoneBook::getSize(void) {
	return SIZE;
}

int PhoneBook::getContain(void) {
	return this->_contain;
}

void PhoneBook::_add_contact(std::string f, std::string l, std::string n, std::string t, std::string s) {
	Contact	contact;

	contact.fname = f;
	contact.lname = l;
	contact.nname = n;
	contact.tel = t;
	contact.secret = s;
	if (this->_contain > 0)
		this->_rearrange();
	this->_list[0] = contact;
	if (this->_contain < SIZE)
		this->_contain++;
}

void PhoneBook::_rearrange(void) {
	for (int i = SIZE - 1; i > 0; i--) {
		if (!this->_list[i - 1].fname.empty())
			this->_list[i] = this->_list[i - 1];
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

void PhoneBook::_print_body_table(std::string search) {
	Contact cnt;
	int		found;

	found = 0;
	for(int i = 0; i < SIZE; i++) {
		cnt = this->_list[i];
		if (cnt.fname.find(search) != std::string::npos)
		{
			this->_print_row_contact(i, cnt);
			found++;
		}
	}
}

void PhoneBook::_print_row_contact(int idx, Contact cnt) {
	int width = 10;

	std::cout << "| " << (idx + 1) << " | ";
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
