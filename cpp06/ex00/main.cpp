#include <iostream>
#include <cmath>
#include <cassert>
#include "ScalarConverter.hpp"

template<typename T>
bool EXPECT_NEAR(const T a, const T b) {
	return (std::fabs(a-b) < 1e-6);
}

void TEST() {
	// char
	{
		try {
			ScalarConverter::Result result = ScalarConverter::convert("a");
			assert(result.char_ == 'a');
			assert(result.int_ == static_cast<int>('a'));
			assert(EXPECT_NEAR(result.float_, static_cast<float>('a')));
			assert(EXPECT_NEAR(result.double_, static_cast<double>('a')));
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// int
	{
		try {
			ScalarConverter::Result result = ScalarConverter::convert("123");
			assert(result.char_ == static_cast<char>(123));
			assert(result.int_ == 123);
			assert(EXPECT_NEAR(result.float_, static_cast<float>(123)));
			assert(EXPECT_NEAR(result.double_, static_cast<double>(123)));
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// float
	{
		try {
			ScalarConverter::Result result = ScalarConverter::convert("1.2f");
			assert(result.char_ == static_cast<char>(1.2f));
			assert(result.int_ == static_cast<int>(1.2f));
			assert(EXPECT_NEAR(result.float_, 1.2f));
			assert(EXPECT_NEAR(result.double_, static_cast<double>(1.2f)));
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// double
	{
		try {
			ScalarConverter::Result result = ScalarConverter::convert("4.2");
			assert(result.char_ == static_cast<char>(4.2));
			assert(result.int_ == static_cast<int>(4.2));
			assert(EXPECT_NEAR(result.float_, static_cast<float>(4.2)));
			assert(EXPECT_NEAR(result.double_, 4.2));
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	// error cases
	{
		try {
			ScalarConverter::convert(".42");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert(".42f");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("42.");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("4.2f.");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("-12-3");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("-21.-3");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("2147483648");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("-123456789012345678901234567890");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("2-1474.83648f");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("NAn");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("+infff");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
	{
		try {
			ScalarConverter::convert("-Inff");
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
	}
}

signed main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	
	try {
		// test case here
		// TEST();
		ScalarConverter::convert(av[1]);	
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
