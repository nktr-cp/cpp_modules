#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

signed main() {
	// normal test
	std::cout << "Test1" << std::endl;
	try {
		Bureaucrat b("bureauro", 42);
		Form f("test", 120, 120);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		// std::cout << "\033[32m" << "Should reach here" << std::endl << "\033[0m";	
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test2" << std::endl;
	try {
		Bureaucrat b("bureauro", 42);
		Form f("test", 12, 12);
		b.signForm(f);
		// std::cout << "\033[32m" << "Should reach here" << std::endl << "\033[0m";	
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test3" << std::endl;
	try {
		Form f("test", 0, 42);
		std::cout << f << std::endl;
		// std::cout << "\033[31m" << "Should not reach here" << std::endl << "\033[0m";		
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test4" << std::endl;
	try {
		Form f("test", 1234, 42);
		std::cout << f << std::endl;
		// std::cout << "\033[31m" << "Should not reach here" << std::endl << "\033[0m";		
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test5" << std::endl;
	try {
		Form f("test", 42, 0);
		std::cout << f << std::endl;
		// std::cout << "\033[31m" << "Should not reach here" << std::endl << "\033[0m";		
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test6" << std::endl;
	try {
		Form f("test", 42, 150);
		std::cout << f << std::endl;
		// std::cout << "\033[32m" << "Should reach here" << std::endl << "\033[0m";			
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "++++++++++++++++++++++++++" << std::endl;
	std::cout << "Test7" << std::endl;
	try {
		Form f("test", 42, 151);
		std::cout << f << std::endl;
		// std::cout << "\033[32m" << "Should reach here" << std::endl << "\033[0m";	
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}