#include <iostream>

int main() {
	std::string org = "HI THIS IS BRAIN";
	std::string *stringPTR = &org;
	std::string &stringREF = org;

	std::cout << "Memory address of the string variable: " << &org << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of the string variable: " << org << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}