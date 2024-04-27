#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name_("default"),
	grade_(100)
{}

Bureaucrat::Bureaucrat(const std::string name,unsigned int grade)
	: name_(name),
		grade_(grade)
{
	if (grade < Bureaucrat::MAXGRADE) {
		throw GradeTooHighException();
	} else if (grade > Bureaucrat::MINGRADE) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name_(other.getName())
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other) {
		return *this;
	}

	this->grade_ = other.grade_;	
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low!";
}

void Bureaucrat::incrementGrade() {
	if (this->grade_ == Bureaucrat::MAXGRADE) {
		throw GradeTooHighException();
	}
	--this->grade_;
}

void Bureaucrat::decrementGrade() {
	if (this->grade_ == Bureaucrat::MINGRADE) {
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
