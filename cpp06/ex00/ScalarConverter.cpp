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
	this->convert();
	this->printResult();
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
:	input_(other.input_)
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
	// specific input?
	const std::string specific[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
	for (size_t i=0; i<sizeof(specific) / sizeof(std::string); i++) {
		if (this->input_.compare(specific[i]) == 0) {
			this->type_ = SPEC_T;
			return;
		}
	}

	// char?
	if (this->input_.size() == 1 && this->input_.find_first_of("0123456789") == std::string::npos) {
		this->type_ = CHAR_T;
		return;
	}

	// int?
	if (this->input_.find_first_not_of("-0123456789") == std::string::npos) {
		if (this->input_.find_first_of("-") == 0 || this->input_.find_first_of("-") == std::string::npos) {
			this->type_ = INT_T;
		} else {
			this->type_ = ERROR_T;
		}
		return;
	}

	// double?
	if (this->input_.find_first_not_of("-0123456789.") == std::string::npos) {
		// exclude multiple '-' or '.'
		// example - ".42.", "..42", "-42.-"
		if ((this->input_.find_first_of("-") != this->input_.find_last_of("-")) 
				|| (this->input_.find_first_of(".") != this->input_.find_last_of("."))) {
					this->type_ = ERROR_T;
					return;
		}

		// check position
		// example - "4.-2", "-.42", ".42"
		if (this->input_.find_first_of("-") != std::string::npos) {
			if (this->input_.find_first_of("-") != 0) {
				this->type_ = ERROR_T;
				return;
			} else if (this->input_.find_first_of(".") <= 1) {
					this->type_ = ERROR_T;
					return;
			}
		} else {
			if (this->input_.find_first_of(".") != std::string::npos &&
					this->input_.find_first_of(".") == 0) {
						this->type_ = ERROR_T;
						return;
			}
		}

		this->type_ = DOUBLE_T;
		return;
	}

	// float?
	if (this->input_.find_first_not_of("-0123456789f") != std::string::npos) {
		assert(this->input_.find_first_of("f") != std::string::npos);
		if (this->input_.find_first_of("f") != this->input_.find_last_of("f") ||
				this->input_.find_first_of("f") != this->input_.length() - 1) {
					this->type_ = ERROR_T;
					return;
		}

		// exclude multiple '-' or '.'
		// example - ".42.", "..42", "-42.-"
		if ((this->input_.find_first_of("-") != this->input_.find_last_of("-")) 
				|| (this->input_.find_first_of(".") != this->input_.find_last_of("."))) {
					this->type_ = ERROR_T;
					return;
		}

		// check position
		// example - "4.-2", "-.42", ".42"
		if (this->input_.find_first_of("-") != std::string::npos) {
			if (this->input_.find_first_of("-") != 0) {
				this->type_ = ERROR_T;
				return;
			} else if (this->input_.find_first_of(".") <= 1) {
					this->type_ = ERROR_T;
					return;
			}
		} else {
			if (this->input_.find_first_of(".") != std::string::npos &&
					this->input_.find_first_of(".") == 0) {
						this->type_ = ERROR_T;
						return;
			}
		}

		this->type_ = FLOAT_T;
		return;
	}

	this->type_ = ERROR_T;
	return;
}

void ScalarConverter::convert() {
	switch(this->type_) {
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
			throw ScalarConverter::InvalidInput();
	}
}

void ScalarConverter::convertChar() {
	this->char_ = static_cast<char>(this->input_.front());
	this->int_ = static_cast<int>(this->char_); 
	this->float_ = static_cast<float>(this->char_); 
	this->double_ = static_cast<double>(this->char_); 
}

void ScalarConverter::convertInt() {
	// detect overflow
	char *end;
	const char* sptr = this->input_.c_str();
	double check = strtod(sptr, &end);
	if (end == NULL || *end != '\0') {
		std::cerr << "Error while converting to double" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max()) {
		throw ScalarConverter::IntOverflowDetected();
	}


	this->int_ = atoi(sptr);

	this->char_ = static_cast<char>(this->int_);
	this->float_ = static_cast<float>(this->int_);
	this->double_ = static_cast<double>(this->int_);
}

void ScalarConverter::convertFloat() {
	const char* s_ptr = this->input_.c_str();
	this->float_ = atof(s_ptr);

	this->char_ = static_cast<char>(this->float_);
	this->int_ = static_cast<int>(this->float_);
	this->double_ = static_cast<double>(this->float_);	
}

void ScalarConverter::convertDouble() {
	char *end;
	const char* sptr = this->input_.c_str();
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
	assert(this->type_ != ERROR_T);

	const float eps = 1e-10;

	// char
	if (this->type_ == SPEC_T) {
		std::cout << "char: impossible" << std::endl;
	} else {
		if (isprint(this->char_)) {
			std::cout << "char: '" << this->char_ << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	}

	// int
	if (this->type_ == SPEC_T) {
		std::cout << "int: impossble" << std::endl;
	} else {
		std::cout << "int: " << this->int_ << std::endl;
	}

	// float
	if (this->type_ == SPEC_T) {
		if (this->input_.compare("nan") == 0 || this->input_.compare("nanf") == 0) {
			std::cout << "float: nanf" << std::endl;
		} else if (this->input_.front() == '+') {
			std::cout << "float: +inff" << std::endl;
		} else {
			assert(this->input_.front() == '-');
			std::cout << "float: -inff" << std::endl;
		}
	} else {
		std::cout << "float: " << this->float_;
		if (this->float_ - this->int_ < eps) {
			std::cout << ".0";
		}
		std::cout << "f" << std::endl;
	}

	// double
	if (this->type_ == SPEC_T) {
		if (this->input_.compare("nan") == 0 || this->input_.compare("nanf") == 0) {
			std::cout << "double: nan" << std::endl;
		} else if (this->input_.front() == '+') {
			std::cout << "double: +inf" << std::endl;
		} else {
			assert(this->input_.front() == '-');
			std::cout << "double: -inf" << std::endl;
		}
	} else {
		std::cout << "double: " << this->double_;
		if (this->float_ - this->int_ < eps) {
			std::cout << ".0";
		}
		std::cout << std::endl;
	}
}

const char* ScalarConverter::IntOverflowDetected::what() const throw() {
	return "Overflow detected!!";
}

const char* ScalarConverter::InvalidInput::what() const throw() {
	return "Invalid argument!!";
}
