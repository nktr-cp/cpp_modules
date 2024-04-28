#include <iostream>
#include "ScalarConverter.hpp"

signed main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	
	try {
		ScalarConverter::convert(av[1]); // returns result
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
