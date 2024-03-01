#ifndef SCALAR_CONVERTER_H_
#define SCALAR_CONVERTER_H_

#include <string>

typedef enum {
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

		ScalarConverter& operator=(const ScalarConverter&);

		~ScalarConverter();

		void judgeType();
		void convertChar();
		void convertInt();
		void convertFloat();
		void convertDouble();
		void printResult() const;

		e_type getType() const;
		const std::string& getInput() const;
		char getChar() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
};

#endif // SCALAR_CONVERTER_H_