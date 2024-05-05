#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
: numbers_(std::vector<int>()),
	paired_numbers_(std::vector<std::pair<int,int> >()),
	main_chain_()
{}

PmergeMe::PmergeMe(std::vector<int>& vec)
: numbers_(vec),
	paired_numbers_(std::vector<std::pair<int,int> >()),
	main_chain_()
{}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other) {
		return *this;
	}

	this->numbers_.clear();
	numbers_ = other.numbers_;
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
}

void PmergeMe::InsertByJacobsthal() {
	std::vector<int> is_inserted(paired_numbers_.size(), 0);
	// Place the element paired with the smallest element of mainChain at the beginning of mainChain.
	int v = paired_numbers_[0].second;
	std::vector<int>::iterator it = lower_bound(main_chain_.begin(), main_chain_.end(), v);
	main_chain_.insert(it, v);
	is_inserted[0] = true;

	size_t prev = 0, cur = 1;
	while (cur < paired_numbers_.size()) {
		if (!is_inserted[cur]) {
			int v = paired_numbers_[cur].second;
			std::vector<int>::iterator it = lower_bound(main_chain_.begin(), main_chain_.end(), v);
			main_chain_.insert(it, v);
			is_inserted[cur] = true;
		}

		// jacobsthal sequence
		int next = cur + prev * 2;
		prev = cur;
		cur = next;
	}

	for (size_t i=0; i<paired_numbers_.size(); i++) {
		if (!is_inserted[i]) {
			int v = paired_numbers_[i].second;
			std::vector<int>::iterator it = lower_bound(main_chain_.begin(), main_chain_.end(), v);
			main_chain_.insert(it, v);
			is_inserted[i] = true;
		}
	}

	if (numbers_.size() % 2) {
		int v = numbers_.back();
		std::vector<int>::iterator it = lower_bound(main_chain_.begin(), main_chain_.end(), v);
		main_chain_.insert(it, v);
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
