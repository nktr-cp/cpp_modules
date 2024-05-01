#include <iostream>
#include <string>
#include "Array.hpp"

signed main(signed, char**) {
	std::cout << "=======int=======" << std::endl;
	{
		Array<int> defaul;
		std::cout << defaul.size() << std::endl;
		Array<int> arr(42);
		std::cout << arr.size() << std::endl;
		for (int i=0; i<42; i++) {
			arr[i] = i;
		}
		Array<int> cpy_arr(arr);
		std::cout << cpy_arr.size() << std::endl;

		try {
			std::cout << arr[20] << std::endl;
			arr[20] = 1234567;
			std::cout << arr[20] << std::endl;
			std::cout << arr[50] << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << cpy_arr[20] << std::endl;
			cpy_arr[20] = 1234567;
			std::cout << cpy_arr[20] << std::endl;
			std::cout << cpy_arr[50] << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=======string=======" << std::endl;
	{
		Array<std::string> defaul;
		std::cout << defaul.size() << std::endl;
		Array<std::string> arr(42);
		std::cout << arr.size() << std::endl;
		for (int i=0; i<42; i++) {
			arr[i] = "how are you";
		}
		Array<std::string> cpy_arr(arr);
		std::cout << cpy_arr.size() << std::endl;

		try {
			std::cout << arr[20] << std::endl;
			arr[20] = "not too bad";
			std::cout << arr[20] << std::endl;
			std::cout << arr[50] << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			std::cout << cpy_arr[20] << std::endl;
			cpy_arr[20] = "not too bad";
			std::cout << cpy_arr[20] << std::endl;
			std::cout << cpy_arr[50] << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
