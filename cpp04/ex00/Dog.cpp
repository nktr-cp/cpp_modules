#include <iostream>
#include "Dog.h"

Dog::Dog() {
	std::cerr << "Dog class default constructor called." << std::endl;
	this->type_ = "Dog";
}

Dog::Dog(const Dog& other) {
	std::cerr << "Dog class copy constructor called." << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cerr << "Dog class destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cerr << "Dog class copy assignment called." << std::endl;
	if (this == &other) {
		return *this;
	}

	Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog makes sound: Woof Woof" << std::endl;
}