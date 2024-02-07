#include <iostream>
#include "Harl.h"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <log level>" << std::endl;
		return EXIT_FAILURE;
	}

	Harl harl;
	std::string level(av[1]);

	harl.complain(level);
}