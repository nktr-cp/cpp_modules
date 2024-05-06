#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
: numbers_(std::vector<int>()),
	paired_numbers_(std::vector<std::pair<int,int> >()),
	main_chain_(std::vector<int>()),
	remaining_chain_(std::vector<int>())
{}

PmergeMe::PmergeMe(std::vector<int>& vec)
: numbers_(vec),
	paired_numbers_(std::vector<std::pair<int,int> >()),
	main_chain_(std::vector<int>()),
	remaining_chain_(std::vector<int>())
{}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other) {
		return *this;
	}

	numbers_ = other.numbers_;
	paired_numbers_ = other.paired_numbers_;
	main_chain_ = other.main_chain_;
	remaining_chain_ = other.remaining_chain_;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::CreateVectorPairs() {
	for (size_t i=0; i+1<numbers_.size(); i+=2) {
		paired_numbers_.push_back(std::make_pair(numbers_[i], numbers_[i+1]));
	}
}

void PmergeMe::SwapElements() {
	for (size_t i=0; i<paired_numbers_.size(); i++) {
		if (paired_numbers_[i].first < paired_numbers_[i].second) {
			std::swap(paired_numbers_[i].first, paired_numbers_[i].second);
		}
	}
}

void PmergeMe::merge(int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	std::vector<std::pair<int,int> > A(n1), B(n2);
	for (int i=0; i<n1; i++) A[i] = paired_numbers_[l+i];
	for (int i=0; i<n2; i++) B[i] = paired_numbers_[m+1+i];

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (A[i] < B[j]) paired_numbers_[k++] = A[i++];
		else paired_numbers_[k++] = B[j++];
	}
	while (i < n1) paired_numbers_[k++] = A[i++];
	while (j < n2) paired_numbers_[k++] = B[j++];
}

void PmergeMe::MergeSort(int l, int r) {
	if (l < r) {
		int m = l + (r-l) / 2;
		MergeSort(l, m);
		MergeSort(m+1, r);
		merge(l, m, r);
	}
}

void PmergeMe::StructMainChain() {
	for (size_t i=0; i<paired_numbers_.size(); i++) {
		main_chain_.push_back(paired_numbers_[i].first);
	}

	for (size_t i=0; i<paired_numbers_.size(); i++) {
		remaining_chain_.push_back(paired_numbers_[i].second);
	}
	if (numbers_.size() % 2) {
		remaining_chain_.push_back(numbers_.back());
	}
}

void PmergeMe::BinaryInsertion(int v) {
	std::vector<int>::iterator it = lower_bound(main_chain_.begin(), main_chain_.end(), v);
	main_chain_.insert(it, v);
}

void PmergeMe::InsertByJacobsthal() {
	// Place the element paired with the smallest element of mainChain at the beginning of mainChain.
	BinaryInsertion(remaining_chain_[0]);

	size_t inserted_number_count = 1;

	size_t prev_group_size = 0;
	size_t cur_group_size = 2;

	while (inserted_number_count + cur_group_size < remaining_chain_.size()) {
		size_t index = inserted_number_count + cur_group_size - 1;
		while (index >= inserted_number_count) {
			BinaryInsertion(remaining_chain_[index--]);
		}

		inserted_number_count += cur_group_size;
		size_t next_group_size = cur_group_size + 2 * prev_group_size;
		prev_group_size = cur_group_size;
		cur_group_size = next_group_size;
	}

	for (size_t i=remaining_chain_.size()-1; i>=inserted_number_count; i--) {
		BinaryInsertion(remaining_chain_[i]);
	}
}

void PmergeMe::merge_insertion_sort() {
	this->CreateVectorPairs();
	this->SwapElements();
	this->MergeSort(0, static_cast<int>(paired_numbers_.size()) - 1);
	this->StructMainChain();
	this->InsertByJacobsthal();
}

void PmergeMe::print_numbers() const {
	for (std::vector<int>::const_iterator it = numbers_.begin(); it != numbers_.end(); ++it) {
		std::cout << ((it == numbers_.begin()) ? "" : " ") << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::print_mainChain() const {
	for (std::vector<int>::const_iterator it = main_chain_.begin(); it != main_chain_.end(); ++it) {
		std::cout << ((it == main_chain_.begin()) ? "" : " ") << *it;
	}
	std::cout << std::endl;
}
