#include <iostream>
#include "Cure.h"

Cure::Cure() : AMateria("cure") {
	std::cerr << "Cure class default constructor called." << std::endl;
}

Cure::Cure(const Cure& other) {
	std::cerr << "Cure copy constructor called." << std::endl;
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	std::cerr << "Cure copy assignment called." << std::endl;
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {
	std::cerr << "Cure class destructor called." << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
