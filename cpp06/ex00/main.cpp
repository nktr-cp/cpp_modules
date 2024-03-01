#include <iostream>
#include "ScalarConverter.h"

signed main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	
	try {
		ScalarConverter converter(av[1]);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
