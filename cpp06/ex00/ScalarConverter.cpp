#include <iostream>
#include "ScalarConverter.h"

// -----------------------------------------------
ScalarConverter::ScalarConverter() {
	std::cerr << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input)
:	input_(input)
{
	std::cerr << "ScalarConverter constructor called" << std::endl;
	this->judgeType();
	this->printResult();
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
:	input_(other.getInput())
{
	std::cerr << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
	this->printResult();
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cerr << "ScalarConverter copy assignment called" << std::endl;
	if (this == &other) {
		return *this;
	}

	this->type_ = other.type_;
	this->char_ = other.char_;
	this->int_ = other.int_;
	this->float_ = other.float_;
	this->double_ = other.double_;

	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cerr << "ScalarConverter destructor called" << std::endl;
}

// -----------------------------------------------
void ScalarConverter::judgeType() {
	// TODO
	// Here, set this->type_
	// Execute conversion at the same time
}

void ScalarConverter::convertChar() {
	this->char_ = static_cast<char>(this->getInput().front());
	this->int_ = static_cast<int>(this->char_); 
	this->float_ = static_cast<float>(this->char_); 
	this->double_ = static_cast<double>(this->char_); 
}

void ScalarConverter::convertInt() {
	const char* s_ptr = this->getInput().c_str();
	this->int_ = atoi(s_ptr);

	this->char_ = static_cast<char>(this->int_);
	this->float_ = static_cast<float>(this->int_);
	this->double_ = static_cast<double>(this->int_);
}

void ScalarConverter::convertFloat() {
	const char* s_ptr = this->getInput().c_str();
	this->float_ = atof(s_ptr);

	this->char_ = static_cast<char>(this->float_);
	this->int_ = static_cast<int>(this->float_);
	this->double_ = static_cast<double>(this->float_);	
}

void ScalarConverter::convertDouble() {
	char *end;
	const char* sptr = this->getInput().c_str();
	this->double_ = strtod(sptr, &end);

	if (end == NULL || *end != '\0') {
		std::cerr << "Error while converting to double" << std::endl;
		exit(EXIT_FAILURE);
	}

	this->char_ = static_cast<char>(this->double_);
	this->int_ = static_cast<int>(this->double_);
	this->float_ = static_cast<float>(this->double_);
}

void ScalarConverter::printResult() const {
	// TODO
}

// -----------------------------------------------

const std::string& ScalarConverter::getInput() const {
	return this->input_;
}

e_type ScalarConverter::getType() const {
	return this->type_;
}

char ScalarConverter::getChar() const {
	return this->char_;
}

int ScalarConverter::getInt() const {
	return this->int_;
}

float ScalarConverter::getFloat() const {
	return this->float_;
}

double ScalarConverter::getDouble() const {
	return this->double_;
}
