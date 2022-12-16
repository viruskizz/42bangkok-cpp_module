#include "MutantStack.hpp"
#include <cstdlib>

int main() {
	srand(time(NULL));
	{
		std::cout << "====== Standard Stack =======" << std::endl;
		std::stack<int> stack;
		stack.push(21);
		stack.push(22);
		stack.push(24);
		stack.push(25);

		stack.pop();

		for (size_t i = 0; i < stack.size(); i++) {
			std::cout << (stack.top() - i) << std::endl;
		}
	}
	{
		std::cout << "====== MutantStack Stack =======" << std::endl;
		MutantStack<int> mystack;
		for (int i = 0; i < 5; i++)
			mystack.push(rand() % 10);
		for (MutantStack<int>::iterator it = mystack.begin(); it < mystack.end(); it++)
			std::cout << *it << std::endl;
	}
	{
		std::cout << "====== Subject Main =======" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it++ << std::endl;
		}
		std::stack<int> s(mstack);
	}
	return 0;
}
