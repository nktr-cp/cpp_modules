#include <sstream>
#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

signed main(signed ac, char** av) {
	try {
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

		PmergeMe::Vector vector_merger(numbers);
		clock_t start_vec = clock();
		vector_merger.merge_insertion_sort();
		clock_t end_vec = clock();

		std::cout << "Before: ";
		vector_merger.print_numbers();
		std::cout << "After: ";
		vector_merger.print_mainChain();

		double elapsed_time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range " << std::setw(4) << ac - 1
			<< " elements with std::vector : " << elapsed_time_vec << " us" << std::endl;

		PmergeMe::Deque deque_merger(numbers);
		clock_t start_deque = clock();
		deque_merger.merge_insertion_sort();
		clock_t end_deque = clock();

		double elapsed_time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range " << std::setw(4) << ac - 1
			<< " elements with std::deque : " << elapsed_time_deque << " us" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
