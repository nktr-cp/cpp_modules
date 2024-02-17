#include <iostream>
#include "WrongCat.h"

WrongCat::WrongCat() {
	std::cerr << "WrongCat class default constructor called." << std::endl;
	this->type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cerr << "WrongCat class copy constructor called." << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	std::cerr << "WrongCat class destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cerr << "WrongCat class copy assignment called." << std::endl;
	if (this == &other) {
		return *this;
	}

	WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat makes sound: Meow Meow?" << std::endl;
}