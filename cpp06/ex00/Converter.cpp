#include <iostream>
#include "Converter.hpp"

// -----------------------------------------------
Converter::Converter() {}

Converter::Converter(const std::string input)
:	input_(input)
{
	judgeType();
	convert();
	printResult();
}

Converter::Converter(const Converter& other)
:	input_(other.input_)
{
	*this = other;
	printResult();
}

Converter& Converter::operator=(const Converter& other) {
	if (this == &other) {
		return *this;
	}

	type_ = other.type_;
	char_ = other.char_;
	int_ = other.int_;
	float_ = other.float_;
	double_ = other.double_;

	return *this;
}

Converter::~Converter() {}

// -----------------------------------------------
void Converter::judgeType() {
	// specific input?
	const std::string specific[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
	for (size_t i=0; i<sizeof(specific) / sizeof(std::string); i++) {
		if (input_.compare(specific[i]) == 0) {
			type_ = SPEC_T;
			return;
		}
	}

	// char?
	if (input_.size() == 1 && input_.find_first_of("0123456789") == std::string::npos) {
		type_ = CHAR_T;
		return;
	}

	// int?
	if (input_.find_first_not_of("-0123456789") == std::string::npos) {
		if (input_.find_first_of("-") == input_.find_last_of("-")) {
			type_ = INT_T;
		} else {
			type_ = ERROR_T;
		}
		return;
	}

	// double?
	if (input_.find_first_not_of("-0123456789.") == std::string::npos) {
		// exclude multiple '-' or '.'
		// example - ".42.", "..42", "-42.-"
		if ((input_.find_first_of("-") != input_.find_last_of("-")) 
				|| (input_.find_first_of(".") != input_.find_last_of("."))) {
					type_ = ERROR_T;
					return;
		}

		// check position
		// example - "4.-2", "-.42", ".42"
		if (input_.find_first_of("-") != std::string::npos) {
			// - not in the start of input
			if (input_.find_first_of("-") != 0) {
				type_ = ERROR_T;
				return;
			} else if (input_.find_first_of(".") <= 1) {
				type_ = ERROR_T;
				return;
			}
		} else if (input_.find_first_of(".") == 0) {
				type_ = ERROR_T;
				return;
		}

		// . at the end
		if (input_.find_first_of(".") == input_.size() - 1) {
			type_ = ERROR_T;
			return;
		}

		type_ = DOUBLE_T;
		return;
	}

	// float?
	if (input_.find_first_not_of("-0123456789.f") == std::string::npos) {
		// multiple 'f' or 'f' not at the end
		if (input_.find_first_of("f") != input_.find_last_of("f") ||
				input_.find_first_of("f") != input_.length() - 1) {
					type_ = ERROR_T;
					return;
		}

		// exclude multiple '-' or '.'
		if ((input_.find_first_of("-") != input_.find_last_of("-")) 
				|| (input_.find_first_of(".") != input_.find_last_of("."))) {
					type_ = ERROR_T;
					return;
		}

		// check position
		// example - "4.-2", "-.42", ".42"
		if (input_.find_first_of("-") != std::string::npos) {
			// - not in the start of input
			if (input_.find_first_of("-") != 0) {
				type_ = ERROR_T;
				return;
			} else if (input_.find_first_of(".") <= 1) {
				type_ = ERROR_T;
				return;
			}
		} else if (input_.find_first_of(".") == 0) {
				type_ = ERROR_T;
				return;
		}

		// . at the end
		if (input_.find_first_of(".") == input_.size() - 1) {
			type_ = ERROR_T;
			return;
		}

		type_ = FLOAT_T;
		return;
	}

	// no matching type
	type_ = ERROR_T;
	return;
}

void Converter::convert() {
	switch(getType()) {
		case SPEC_T:
			return;
		case INT_T:
			convertInt();
			return;
		case CHAR_T:
			convertChar();
			return;
		case FLOAT_T:
			convertFloat();
			return;
		case DOUBLE_T:
			convertDouble();
			return;
		default:
			throw Converter::InvalidInput();
	}
}

void Converter::convertChar() {
	char_ = static_cast<char>(input_.front());
	int_ = static_cast<int>(char_); 
	float_ = static_cast<float>(char_); 
	double_ = static_cast<double>(char_); 
}

void Converter::convertInt() {
	// detect overflow before conversion
	char *end;
	const char* sptr = input_.c_str();
	double check = std::strtod(sptr, &end);
	if (end == NULL || *end != '\0') {
		std::cerr << "Error while converting to double" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max()) {
		throw Converter::OverflowDetected();
	}

	int_ = std::atoi(sptr);
	char_ = static_cast<char>(int_);
	float_ = static_cast<float>(int_);
	double_ = static_cast<double>(int_);
}

void Converter::convertFloat() {
	const char* s_ptr = input_.c_str();
	float_ = std::atof(s_ptr);
	char_ = static_cast<char>(float_);
	int_ = static_cast<int>(float_);
	double_ = static_cast<double>(float_);	
}

void Converter::convertDouble() {
	char *end;
	const char* sptr = input_.c_str();
	double_ = std::strtod(sptr, &end);

	if (end == NULL || *end != '\0') {
		std::cerr << "Error while converting to double" << std::endl;
		exit(EXIT_FAILURE);
	}

	char_ = static_cast<char>(double_);
	int_ = static_cast<int>(double_);
	float_ = static_cast<float>(double_);
}

void Converter::printResult() const {
	assert(type_ != ERROR_T);

	const float eps = 1e-10;

	// char
	if (type_ == SPEC_T) {
		std::cout << "char: impossible" << std::endl;
	} else {
		if (std::isprint(char_)) {
			std::cout << "char: '" << char_ << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	}

	// int
	if (type_ == SPEC_T) {
		std::cout << "int: impossble" << std::endl;
	} else {
		std::cout << "int: " << int_ << std::endl;
	}

	// float
	if (type_ == SPEC_T) {
		if (input_.compare("nan") == 0 || input_.compare("nanf") == 0) {
			std::cout << "float: nanf" << std::endl;
		} else if (input_.front() == '+') {
			std::cout << "float: +inff" << std::endl;
		} else {
			assert(input_.front() == '-');
			std::cout << "float: -inff" << std::endl;
		}
	} else {
		std::cout << "float: " << float_;
		if (std::abs(float_ - int_) < eps) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}

	// double
	if (type_ == SPEC_T) {
		if (input_.compare("nan") == 0 || input_.compare("nanf") == 0) {
			std::cout << "double: nan" << std::endl;
		} else if (input_.front() == '+') {
			std::cout << "double: +inf" << std::endl;
		} else {
			assert(input_.front() == '-');
			std::cout << "double: -inf" << std::endl;
		}
	} else {
		std::cout << "double: " << double_;
		if (std::abs(double_ - int_) < eps) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	}
}

const char* Converter::OverflowDetected::what() const throw() {
	return "Overflow detected!!";
}

const char* Converter::InvalidInput::what() const throw() {
	return "Invalid argument!!";
}

// -----------------------------------------------

const std::string& Converter::getInput() const {
	return input_;
}

e_type Converter::getType() const {
	return type_;
}

char Converter::getChar() const {
	return char_;
}

int Converter::getInt() const {
	return int_;
}

float Converter::getFloat() const {
	return float_;
}

double Converter::getDouble() const {
	return double_;
}
