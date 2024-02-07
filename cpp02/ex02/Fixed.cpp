#include <iostream>
#include <cmath>
#include "Fixed.h"

Fixed::Fixed() : value_(0) {
	std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << fractionalBits) {
	std::cerr << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value_(roundf(value * (1<<fractionalBits))) {
	std::cerr << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cerr << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cerr << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cerr << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator>(const Fixed& other) const {
	return this->value_ > other.value_;
}
bool Fixed::operator<(const Fixed& other) const {
	return this->value_ < other.value_;
}
bool Fixed::operator>=(const Fixed& other) const {
	return this->value_ >= other.value_;
}
bool Fixed::operator<=(const Fixed& other) const {
	return this->value_ <= other.value_;
}
bool Fixed::operator==(const Fixed& other) const {
	return this->value_ == other.value_;
}
bool Fixed::operator!=(const Fixed& other) const {
	return this->value_ != other.value_;
}

Fixed Fixed::operator+(const Fixed& other) {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	this->value_++;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed res(*this);
	this->value_++;
	return res;
}
Fixed& Fixed::operator--() {
	this->value_--;
	return *this;	
}
Fixed Fixed::operator--(int) {
	Fixed res(*this);
	this->value_--;
	return res;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a>=b ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a<=b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a>=b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a<=b ? a : b;
}

int Fixed::getRawBits(void) const {
	std::cerr << "getRawBits member function called" << std::endl;
	return this->value_;
}

void Fixed::setRawBits(int const raw) {
	std::cerr << "setRawBits member function called" << std::endl;
	this->value_ = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->value_) / (1 << fractionalBits); 
}

int Fixed::toInt(void) const {
	return this->value_ >> fractionalBits;
}
