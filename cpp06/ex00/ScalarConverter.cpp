#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& dummy) {(void)dummy;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& dummy) {(void)dummy; return *this;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::Result ScalarConverter::convert(const std::string input) {
	ScalarConverter::Result result;
	Converter conv(input);

	result.char_ = conv.getChar();
	result.int_ = conv.getInt();
	result.float_ = conv.getFloat();
	result.double_ = conv.getFloat();

	return result;
}
