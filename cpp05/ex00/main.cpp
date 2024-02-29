#include <iostream>
#include "Bureaucrat.h"

int main() {
	// normal test
	std::cout << "Test1" << std::endl;
	try {
		Bureaucrat a("test", 123);
		Bureaucrat b(a);
		Bureaucrat c;
		c = b;

		a.incrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		a.decrementGrade();
		std::cout << a << std::endl;
	} catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test2" << std::endl;
	// tests that includes exceptions
	try {
		// initialize with grade greater than the maximum value
		Bureaucrat a("tmp", 0);
		std::cout << "Should not reach here!" << std::endl;
	} catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test3" << std::endl;
	try {
		// initialize with grade less than the miminum value
		Bureaucrat a("tmp", 151);
		std::cout << "Should not reach here!" << std::endl;
	} catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test4" << std::endl;
	try {
		Bureaucrat b("tmp", 1);
		b.incrementGrade();
		std::cout << "Should not reach here!" << std::endl;
	} catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test5" << std::endl;
	try {
		Bureaucrat b("tmp", 150);
		b.decrementGrade();
		std::cout << "Should not reach here!" << std::endl;
	} catch(std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
