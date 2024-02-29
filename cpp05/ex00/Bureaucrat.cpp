#include <iostream>
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat()
: name_("default"),
	grade_(100)
{
	std::cerr << "Bureaucrat class default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name,unsigned int grade)
	: name_(name),
		grade_(grade)
{
	std::cerr << "Bureaucrat class constructor called" << std::endl;
	if (grade < Bureaucrat::maxgrade) {
		throw GradeTooLowException();
	} else if (grade > Bureaucrat::mingrade) {
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cerr << "Bureaucrat class copy constructor called" << std::endl;
	*this = other;
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cerr << "Bureaucrat class copy assignment called" << std::endl;
	if (this == &other) {
		return *this;
	}

	// this attribute is constant
	// this->name_ = other.name_;

	this->grade_ = other.grade_;
	
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cerr << "Bureaucrat class destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low!";
}

void Bureaucrat::incrementGrade() {
	if (this->grade_ == Bureaucrat::maxgrade) {
		throw GradeTooHighException();
	}
	--this->grade_;
}

void Bureaucrat::decrementGrade() {
	if (this->grade_ == Bureaucrat::mingrade) {
		throw GradeTooLowException();
	}
	++this->grade_;
}

const std::string& Bureaucrat::getName() const {
	return this->name_;
}

unsigned int Bureaucrat::getGrade() const {
	return this->grade_;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat& a) {
		os << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
	return os;
}
