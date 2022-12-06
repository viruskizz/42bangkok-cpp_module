#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat	a = Bureaucrat("A", 1);
		Bureaucrat	b = Bureaucrat("Bad", 100);
		Form basicForm = Form("Basic", 50);
		std::cout << basicForm << std::endl;
		a.signForm(basicForm);
		b.signForm(basicForm);
	} catch (std::exception &e) {
		std::cout << "catch main" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return 0;
}