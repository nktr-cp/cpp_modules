#ifndef _CONVERTER_HPP_
#define _CONVERTER_HPP_

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

class Converter {
	private:
		std::string input_;
		e_type type_;
		char char_;
		int int_;
		float float_;
		double double_;

	public:
		Converter();

		Converter(const std::string);

		Converter(const Converter&);

		Converter &operator=(const Converter&);

		~Converter();

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

		class OverflowDetected : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		e_type getType() const;
		const std::string& getInput() const;
		char getChar() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
};

#endif // _CONVERTER_HPP_