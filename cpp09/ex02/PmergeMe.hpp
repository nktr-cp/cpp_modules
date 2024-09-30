#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>

#ifdef DEBUG
extern int num_comparison;
#endif  // DEBUG

template <typename Container>
class PmergeMe {
 private:
  PmergeMe(const PmergeMe& other) { (void)other; }
  PmergeMe& operator=(const PmergeMe& other) {
    (void)other;
    return *this;
  }

  int binaryInsertion(Container& mainChain, typename Container::value_type v,
                      int right) {
    int left = 0;
    if (mainChain.size() <= static_cast<size_t>(right)) {
      right = mainChain.size() - 1;
    }
    while (left <= right) {
      int mid = left + (right - left) / 2;
#ifdef DEBUG
      num_comparison++;
#endif  // DEBUG
      if (mainChain[mid] == v) {
        left = mid;
        break;
      } else if (mainChain[mid] < v) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    mainChain.insert(mainChain.begin() + left, v);

    return left;
  }

 public:
  PmergeMe() {}
  ~PmergeMe() {}

  Container mergeInsertionSort(typename Container::iterator first,
                               typename Container::iterator last) {
    const int N = static_cast<int>(std::distance(first, last));
    Container elements(first, last);

    Container sortIndices(N);
    for (int i = 0; i < N; ++i) {
      sortIndices[i] = i;
    }

    if (N <= 1) return sortIndices;

    // first, make pairs of elements
    // if N is odd, the last element is left as it is
    // swap elements so that the larger element is in the first half
    for (int i = 0, j = N / 2; i < N / 2; ++i, ++j) {
#ifdef DEBUG
      num_comparison++;
#endif  // DEBUG
      if (elements[i] < elements[j]) {
        std::swap(elements[i], elements[j]);
        std::swap(sortIndices[i], sortIndices[j]);
      }
    }

    if (N == 2) {
      std::swap(elements[0], elements[1]);
      return sortIndices;
    }

    // sort the first half
    // this will be the permutation of [0..N/2)
    Container first_half =
        mergeInsertionSort(elements.begin(), elements.begin() + N / 2);

    // this variable is used to store the index of the main chain
    // this will be the return value of this function
    Container mainChainIdx(N, -1);
    for (int i = 0; i < N / 2; ++i) {
      mainChainIdx[i] = sortIndices[first_half[i]];
    }
    Container remChainIdx;
    for (int i = 0; i < N / 2; ++i) {
      int idx = mainChainIdx[i];
      int pairedIdx = mainChainIdx[i] >= N / 2 ? idx - N / 2 : idx + N / 2;
      remChainIdx.push_back(pairedIdx);
    }

    Container mainChain, remChain;
    for (int i = 0; i < N / 2; ++i) {
      mainChain.push_back(first[mainChainIdx[i]]);
      remChain.push_back(first[remChainIdx[i]]);
    }
    if (N % 2) {
      remChain.push_back(first[N - 1]);
      remChainIdx.push_back(N - 1);
    }

    // insert first element of remChain
    // it is guaranteed that remChain[0] is the smallest element
    // since mainChain is sorted in ascending order
    // and therefore mainChain[0] is the smallest element in mainChain
    mainChain.insert(mainChain.begin(), remChain.front());
    for (int i = N / 2 - 1; i >= 0; --i) {
      mainChainIdx[i + 1] = mainChainIdx[i];
    }
    mainChainIdx.front() = remChainIdx.front();

    // insert using Jacobsthal
    // Jacobsthal sequence here is defined as follows:
    // J(0) = 0, J(1) = 2, J(n) = J(n-1) + 2 * J(n-2)
    size_t numInserted = 1;
    size_t prevGroupSize = 0;
    size_t curGroupSize = 2;
    // upperBoundIndex: 3 -> 7 -> 15 -> 31 -> 63 -> ...
    size_t upperBoundIndex = (N - 1 < 4 ? N - 1 : 3);

    // insert elements in remChain to mainChain
    // the order of the insertion is determined by Jacobsthal sequence
    // To be more specific, the order is determined by the following:
    // rem_3, rem_2, rem_5, rem_4, rem_11, rem_10, ...
    while (numInserted + curGroupSize < remChain.size()) {
      size_t index = numInserted + curGroupSize - 1;
      while (index >= numInserted) {
        // decide where to insert using binary search
        int insertedIndex =
            binaryInsertion(mainChain, remChain[index], upperBoundIndex - 1);
        // rotate existing elements
        for (int j = N - 1; j > insertedIndex; --j) {
          mainChainIdx[j] = mainChainIdx[j - 1];
        }
        mainChainIdx[insertedIndex] = remChainIdx[index];
        --index;
      }

      // update jacobsthal
      numInserted += curGroupSize;
      size_t nextGroupSize = curGroupSize + 2 * prevGroupSize;
      prevGroupSize = curGroupSize;
      curGroupSize = nextGroupSize;
      upperBoundIndex = 2 * upperBoundIndex + 1;
    }

    for (size_t index = remChain.size() - 1; index >= numInserted; --index) {
      int insertedIndex =
          binaryInsertion(mainChain, remChain[index], upperBoundIndex - 1);
      for (int j = N - 1; j > insertedIndex; --j) {
        mainChainIdx[j] = mainChainIdx[j - 1];
      }
      mainChainIdx[insertedIndex] = remChainIdx[index];
    }
    return mainChainIdx;
  }
};

#endif  // PMERGE_ME_HPP
