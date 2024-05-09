#include <iostream>
#include <cmath>
#include "Fixed.h"

Fixed::Fixed() : value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value * (1 << fractionalBits)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value_(roundf(value * (1<<fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) {
		return (*this);
	}
	this->value_ = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value_;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value_ = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->value_) / (1 << fractionalBits); 
}

int Fixed::toInt(void) const {
	return this->value_ / (1 << fractionalBits);
}
