#include <iostream>
#include "Ice.h"

Ice::Ice() : AMateria("ice") {
	std::cerr << "Ice class default constructor called." << std::endl;
}

Ice::Ice(const Ice& other) {
	std::cerr << "Ice copy constructor called." << std::endl;
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	std::cerr << "Ice copy assignment called." << std::endl;
	// pdf: While assigning a Materia to another,
	// copying the type doesn’t makesense.

	// this does not make sence?
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {
	std::cerr << "Ice class destructor called." << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
