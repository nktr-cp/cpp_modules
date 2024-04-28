#ifndef SCALAR_CONVERTER_HPP_
#define SCALAR_CONVERTER_HPP_

#include "Converter.hpp"

class ScalarConverter {
	private:
		struct Result {
			char char_;
			int int_;
			float float_;
			double double_;
		};

		ScalarConverter();

		ScalarConverter(const ScalarConverter&);

		ScalarConverter &operator=(const ScalarConverter&);

		~ScalarConverter();

	public:
		static Result convert(const std::string);
};

#endif // SCALAR_CONVERTER_HPP_