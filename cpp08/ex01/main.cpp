#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	{
		try {
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			sp.addNumber(4242);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			std::vector<int> vec;
			for (int i=0; i<100000; i++) {
				vec.push_back(i);
			}

			Span sp(100000);
			sp.addNumber(vec.begin(), vec.begin() + 10);

			std::cout << sp.longestSpan() << std::endl;

			sp.addNumber(vec.begin() + 20, vec.begin() + 30);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

			sp.addNumber(vec.begin(), vec.end());
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		try {
			Span sp(100000);

			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MIN);

			std::cout << sp.longestSpan() << std::endl;

			for (int i=0; i<50000; i++) {
				sp.addNumber(i);
			}

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}