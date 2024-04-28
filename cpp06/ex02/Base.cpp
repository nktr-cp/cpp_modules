#include "ABC.hpp"
#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
	int flag = std::rand() % 3;
	switch (flag) {
		case 0:
			std::cout << "generate function returns an object of class A this time!" << std::endl;
			return new A();
		case 1:
			std::cout << "generate function returns an object of class B this time!" << std::endl;
			return new B();
		case 2:
			std::cout << "generate function returns an object of class C this time!" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	// Use property of　 dynamic_cast
	// * returning nullptr on failure
	if (dynamic_cast<A*>(p)) {
		std::cout << "Given argument was a pointer to an object class A!" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Given argument was a pointer to an oject of class B!" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Given argument was a pointer to an object of class C!" << std::endl;
	} else {
		std::cerr << "Provide a pointer to an object of class A, B or C..." << std::endl;
	}
}

void identify(Base& p) {
	try {
		// to avoid `error: expression result unused`
		A& dummy = dynamic_cast<A&>(p);
		(void)dummy;
		std::cout << "Given argument was a reference to an object class A!" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		B& dummy = dynamic_cast<B&>(p);
		(void)dummy;
		std::cout << "Given argument was a reference to an object class B!" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		C& dummy = dynamic_cast<C&>(p);
		(void)dummy;
		std::cout << "Given argument was a reference to an object class C!" << std::endl;
		return;
	} catch (std::exception &e) {}

	std::cerr << "Provide a reference to an object of class A, B or C..." << std::endl;
}

