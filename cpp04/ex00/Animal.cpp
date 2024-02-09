#include <iostream>
#include "Animal.h"

Animal::Animal() : type_("animal") {
	std::cerr << "Animal class default constructor called." << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cerr << "Animal class copy constructor called." << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cerr << "Animal class destructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cerr << "Animal class copy assignment called." << std::endl;
	if (this == &other) {
		return *this;
	}

	this->type_ = other.type_;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Unknown animal makes sound..." << std::endl;
}

const std::string& Animal::getType() const {
	return this->type_;
}