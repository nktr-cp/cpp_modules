#include <iostream>
#include "Cat.h"

Cat::Cat() {
	std::cerr << "Cat class default constructor called." << std::endl;
	this->type_ = "Cat";
}

Cat::Cat(const Cat& other) {
	std::cerr << "Cat class copy constructor called." << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cerr << "Cat class destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cerr << "Cat class copy assignment called." << std::endl;
	if (this == &other) {
		return *this;
	}

	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Cat makes sound: Meow Meow" << std::endl;
}