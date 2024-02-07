#include <iostream>
#include "FileReplacer.h"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);

	FileReplacer file_replacer(filename, s1, s2);
	file_replacer.replace();
}
