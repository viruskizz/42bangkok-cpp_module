#include "Contact.hpp"
#include "iostream"

Contact::Contact(void) {
	return ;
}

void	Contact::showInformation() {
	std::cout << BOLD << CYAN << "== information ==" << RESET << std::endl;
	std::cout << BOLD << "firstname: " << GRAY << this->fname << RESET << std::endl;
	std::cout << BOLD << "lastname: " << GRAY << this->lname << RESET << std::endl;
	std::cout << BOLD << "nickname: "  << GRAY << this->nname << RESET << std::endl;
	std::cout << BOLD << "telephhone: " << GRAY << this->tel << RESET << std::endl;
	std::cout << BOLD << "dark_secret: " << GRAY << this->secret << RESET << std::endl;
}

bool	Contact::formContact() {
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	tel;
	std::string	secret;

	std::cout << "=New contact=" << std::endl;
	std::cout << std::right << "firstname: ", std::getline (std::cin, fname);
	std::cout << std::right << "lastname: ", std::getline (std::cin, lname);
	std::cout << std::right << "nickname: ", std::getline (std::cin, nname);
	std::cout << std::right << "phone: ", std::getline (std::cin, tel);
	std::cout << std::right << "dark secret: ", std::getline (std::cin, secret);
	if (fname.empty() || lname.empty() || nname.empty() || tel.empty() || secret.empty()) {
		std::cout << RED << "Fields cannot be empty" << RESET << std::endl;
		return true;
	} else {
		this->fname = fname;
		this->lname = lname;
		this->nname = nname;
		this->tel = tel;
		this->secret = secret;
		std::cout << ">> Contact added <<" << std::endl;
		return true;
	}
}