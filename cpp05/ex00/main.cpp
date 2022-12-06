#include "Bureaucrat.hpp"

int main() {
	try {
		// Bureaucrat z = Bureaucrat("Z", -1); // overflow
		Bureaucrat a = Bureaucrat("A", 1);
		Bureaucrat b = Bureaucrat("B", 150);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.decrease();
		b.increase();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.increase(); a.increase();	// expected error too high
		// b.decrease(); b.decrease();	// expected error too low;
	} catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << LRED << e.what() << RESET << std::endl;
	} catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << LRED << e.what() << RESET << std::endl;
	} catch (std::exception & e) {
		std::cout << YELLOW << e.what() << RESET << std::endl;
	}
	return 0;
}