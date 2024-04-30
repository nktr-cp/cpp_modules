template<class T>
MutantStack<T>::MutantStack()
: std::stack<T>()
{}

template<class T>
MutantStack<T>::MutantStack(const MutantStack<T>& other)
: std::stack<T>(other)
{}

template<class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
	if (this == &other) {
		return *this;
	}
	std::stack<T>::operator=(other);
	return *this;
}

template<class T>
MutantStack<T>::~MutantStack<T>() {}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}
