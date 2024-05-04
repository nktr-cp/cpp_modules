#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>

/**********************************
https://en.wikipedia.org/wiki/Merge-insertion_sort
procedure:
1. Create a structure of vectors containing pairs of integers, denoted as vec[i] and vec[i+1].
2. Swap elements if vec[i] is less than vec[i+1].
3. Execute merge sort for the first elements of the vector vec,
	creating a sequence mainChain. Ensure that mainChain is an increasing sequence.
4. Place the element paired with the smallest element of mainChain at the beginning of mainChain.
5. Insert the second elements of vec into mainChain using binary search.
	The insertion order is determined by the Jacobsthal sequence.
***********************************/

class PmergeMe {
	private:
		std::vector<int> numbers_;

	public:
		PmergeMe();
		PmergeMe(std::vector<int>&);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();

		void merge_insertion_sort();
		void print_numbers() const;
};

#endif // PMERGE_ME_HPP
