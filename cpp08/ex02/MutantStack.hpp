#ifndef MUTANT_STACK_HPP_
#define MUTANT_STACK_HPP_

#include <stack>

// std::stack has protected attribute c (Container type)
// therefore, nothing to write.
template<class T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack();
		MutantStack(const MutantStack&);
		MutantStack& operator=(const MutantStack&);
		~MutantStack();

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif // MUTANT_STACK_HPP_
