#include "Span.hpp"

int main() {
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "==== generate ===" << std::endl;
		Span ss = Span(10);
		ss.addNumber(99);
		std::vector<int> myvector;
		for (int i = 1; i < 100; i++)
			myvector.push_back(i);
		ss.addNumber(myvector.begin(), myvector.end());
		std::cout << ss << std::endl;
		std::cout << "size = " << ss.getV().size() << std::endl;
		try {
			ss.addNumber(-1);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl; 
		}
	}
	return 0;
}
