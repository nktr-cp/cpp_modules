#include <iostream>
#include <vector>
#include <cassert>
#include "easyfind.hpp"

signed main(void) {
	try {
		std::vector<int> vec;
		for (int i=0; i<=20; i+=2) {
			vec.push_back(i);
		}

		std::cout << "Elements of vector" << std::endl;
		for (size_t i=0; i<vec.size(); i++) {
			std::cout << "+++++++++++++++" << std::endl;
			std::cout << "index: " << i << std::endl;
			std::cout << "value: " << vec[i] << std::endl;
		}

		{
			std::vector<int>::iterator it = easyfind(vec, 10);

			std::cout << "+++++++++++++++" << std::endl;
			std::cout << "Result of easyfind(vec, 10)" << std::endl;
			std::cout << it - vec.begin() << std::endl;
			std::cout << *it << std::endl;
		}
		{
			std::vector<int>::iterator it = easyfind(vec, 100);
			assert(it == vec.end());

			std::cout << "+++++++++++++++" << std::endl;
			std::cout << "Result of easyfind(vec, 100)" << std::endl;
			std::cout << it - vec.begin() << std::endl;
			// std::cout << *it << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}
