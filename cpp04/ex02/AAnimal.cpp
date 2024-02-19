#include <iostream>
#include "AAnimal.h"

AAnimal::AAnimal() : type_("AAnimal") {
	std::cerr << "AAnimal class default constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cerr << "AAnimal class copy constructor called." << std::endl;
	*this = other;
}

AAnimal::~AAnimal() {
	std::cerr << "AAnimal class destructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cerr << "AAnimal class copy assignment called." << std::endl;
	if (this == &other) {
		return *this;
	}

	this->type_ = other.type_;
	return *this;
}

void AAnimal::makeSound() const {
	std::cout << "Unknown AAnimal makes sound..." << std::endl;
}

const std::string& AAnimal::getType() const {
	return this->type_;
}