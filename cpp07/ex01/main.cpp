#include <iostream>
#include <string>
#include "iter.hpp"

// test for integer inputs
// divisors enumeration
template<class T>
void testFunc1(T elem) {
	for (T p=1; p<=elem; p++) {
		if (elem % p == 0) {
			std::cout << p << std::endl;
		}
	}
}

// test for decimal input
template<class T>
void testFunc2(T elem) {
	std::cout << std::ceil(elem) << std::endl;
}

// test for string input
void testFunc3(const std::string& elem) {
	std::string rev(elem);
	std::reverse(rev.begin(), rev.end());
	std::cout << rev << std::endl;
}

// test for boolean input
void testFunc4(const bool& elem) {
	std::cout << (elem ? "YES" : "NO") << std::endl;
}

signed main() {
	// int
	{
		int a[] = {2,5,21,42};
		iter(a, sizeof(a) / sizeof(int), testFunc1<int>);
		std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// long
	{
		long a[] = {120L, 4242L};
		iter(a, sizeof(a) / sizeof(long), testFunc1<long>);
		std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// float
	{
		float a[] = {1.2f, 2.1f, 4.2f, 5.0f};
		iter(a, sizeof(a) / sizeof(float), testFunc2<float>);
		std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// double
	{
		double a[] = {1.2, 2.1, 4.2, 5.0};
		iter(a, sizeof(a) / sizeof(double), testFunc2<double>);
		std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// string
	{
		std::string a[] = {"Hello", "42Tokyo", "nolemonnomelon"};
		iter(a, sizeof(a) / sizeof(std::string), testFunc3);
		std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// bool
	{
		bool a[] = {true, true, false, true, false};
		iter(a, sizeof(a) / sizeof(bool), testFunc4);
		std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
}
