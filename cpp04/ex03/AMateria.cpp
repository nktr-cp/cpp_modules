#include <iostream>
#include "AMateria.h"

AMateria::AMateria() {
	std::cerr << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type_(type) {
	std::cerr << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cerr << "AMateria constructor called" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cerr << "Copy assignment called" << std::endl;
	if (this == &other) {
		return *this;
	}

	this->type_ = other.type_;

	return *this;
}

AMateria::~AMateria() {
	std::cerr << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const {
	return this->type_;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria abstract class used on " << target.getName() << std::endl;
}
