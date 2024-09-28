#include <ctime>
#include <deque>
#include <iomanip>
#include <sstream>
#include <vector>

#include "PmergeMe.hpp"

#ifdef DEBUG
int num_comparison = 0;
#endif  // DEBUG

signed main(signed ac, char** av) {
  try {
    if (ac == 1) {
      std::cout << "Usage: " << av[0] << "<number1> <number2> ..." << std::endl;
      return 1;
    }

    std::vector<int> vNumbers;
    std::deque<int> dNumbers;
    for (int i = 1; i < ac; i++) {
      int num;
      std::stringstream ss(av[i]);
      if (ss >> num && num > 0) {
        vNumbers.push_back(num);
        dNumbers.push_back(num);
      } else {
        std::cout << "Invalid argument: " << av[i] << std::endl;
        return 1;
      }
    }

    {
      PmergeMe<std::vector<int> > vMerger;
      clock_t start_vec = clock();
      std::vector<int> indices =
          vMerger.mergeInsertionSort(vNumbers.begin(), vNumbers.end());
      clock_t end_vec = clock();

#ifdef DEBUG
      std::cout << "Number of comparisons: " << num_comparison << std::endl;
      num_comparison = 0;
#endif  // DEBUG

      std::cout << "Before: ";
      for (size_t i = 0; i < vNumbers.size(); i++) {
        std::cout << vNumbers[i] << (i == vNumbers.size() - 1 ? "\n" : " ");
      }
      std::cout << "After: ";
      for (size_t i = 0; i < indices.size(); i++) {
        std::cout << vNumbers[indices[i]]
                  << (i == indices.size() - 1 ? "\n" : " ");
      }

      double elapsed_time_vec =
          static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
      std::cout << "Time to process a range of " << std::setw(4) << ac - 1
                << " elements with std::vector : " << elapsed_time_vec << "us"
                << std::endl;
    }

    {
      PmergeMe<std::deque<int> > dMerger;
      clock_t start_deq = clock();
      std::deque<int> indices =
          dMerger.mergeInsertionSort(dNumbers.begin(), dNumbers.end());
      clock_t end_deq = clock();

#ifdef DEBUG
      std::cout << "Number of comparisons: " << num_comparison << std::endl;
      num_comparison = 0;
#endif  // DEBUG

      std::cout << "Before: ";
      for (size_t i = 0; i < dNumbers.size(); i++) {
        std::cout << dNumbers[i] << (i == dNumbers.size() - 1 ? "\n" : " ");
      }
      std::cout << "After: ";
      for (size_t i = 0; i < indices.size(); i++) {
        std::cout << dNumbers[indices[i]]
                  << (i == indices.size() - 1 ? "\n" : " ");
      }

      double elapsed_time_deq =
          static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1e6;
      std::cout << "Time to process a range of " << std::setw(4) << ac - 1
                << " elements with std::deque : " << elapsed_time_deq << "us"
                << std::endl;
    }

  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
}
