#include <sstream>
#include "PmergeMe.hpp"

signed main(signed ac, char** av) {
	if (ac == 1) {
		std::cout << "Usage: " << av[0] << "<number1> <number2> ..." << std::endl;
		return 1;
	}

	std::vector<int> numbers;
	for (int i=1; i<ac; i++) {
		int num;
		std::stringstream ss(av[i]);
		if (ss >> num && num > 0) {
			numbers.push_back(num);
		} else {
			std::cout << "Invalid argument: " << av[i] << std::endl;
			return 1;
		}
	}

	PmergeMe merger(numbers);
	merger.merge_insertion_sort();
	merger.print_numbers();

	return 0;
}
