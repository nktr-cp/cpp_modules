#include <iostream>
#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type_("animal") {
	std::cerr << "WrongAnimal class default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cerr << "WrongAnimal class copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal() {
	std::cerr << "WrongAnimal class destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cerr << "WrongAnimal class copy assignment called." << std::endl;
	if (this == &other) {
		return *this;
	}

	this->type_ = other.type_;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong animal makes sound..." << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return this->type_;
}