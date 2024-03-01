#ifndef SCALAR_CONVERTER_H_
#define SCALAR_CONVERTER_H_

#include <string>
#include <cassert>

typedef enum {
	SPEC_T,
	INT_T,
	CHAR_T,
	FLOAT_T,
	DOUBLE_T,
	ERROR_T
} e_type;

class ScalarConverter {
	private:
		const std::string input_;
		e_type type_;
		char char_;
		int int_;
		float float_;
		double double_;

		ScalarConverter();

	public:
		ScalarConverter(const std::string);

		ScalarConverter(const ScalarConverter&);

		ScalarConverter &operator=(const ScalarConverter&);

		~ScalarConverter();

		void judgeType();
		void convert();
		void convertChar();
		void convertInt();
		void convertFloat();
		void convertDouble();
		void printResult() const;

		class InvalidInput : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class IntOverflowDetected : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif // SCALAR_CONVERTER_H_