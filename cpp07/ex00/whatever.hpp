#ifndef WHATEVER_HPP_
#define WHATEVER_HPP_

template<class T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// https://en.cppreference.com/w/cpp/algorithm/min
template<class T>
const T& min(const T& a, const T& b) {
	return a < b ? a : b;
}

template<class T>
const T& max(const T& a, const T& b) {
	return a > b ? a : b;
}

#endif // WHATEVER_HPP_
