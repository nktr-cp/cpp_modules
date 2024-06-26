#include <iostream>
#include <set>
#include "MutantStack.hpp"

int main() {
	{
		try {
			MutantStack<int> mstack;
			mstack.push(5);
			mstack.push(17);
			std::cout << mstack.top() << std::endl;
			mstack.pop();
			std::cout << mstack.size() << std::endl;
			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			mstack.push(0);
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::stack<int> s(mstack);
		} catch (std::exception &e) {
			std::cout << "Exception thrown: " << e.what() << std::endl;
		}
	}
	{
		try {
			MutantStack<int> ms;
			for (int i=0; i<5000; i++) {
				ms.push(i);
			}
			std::cout << ms.size() << std::endl;
			int val = 0;
			for (MutantStack<int>::iterator it=ms.begin(); it!=ms.end(); ++it) {
				val += *it;
			}
			std::cout << val << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception thrown: " << e.what() << std::endl;
		}
	}
	{
		try {
			std::set<int> ms;
			for (int i=0; i<5000; i++) {
				ms.insert(i);
			}
			std::cout << ms.size() << std::endl;
			int val = 0;
			for (std::set<int>::iterator it=ms.begin(); it!=ms.end(); ++it) {
				val += *it;
			}
			std::cout << val << std::endl;
		} catch (std::exception &e) {
			std::cout << "Exception thrown: " << e.what() << std::endl;
		}
	}
}