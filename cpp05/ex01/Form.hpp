#ifndef FORM_HPP_
#define FORM_HPP_

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class Form {
	private:
		static const unsigned int MAXGRADE = 1;
		static const unsigned int MINGRADE = 150;

		const std::string name_;
		bool is_signed_;
		const unsigned int sign_grade_;
		const unsigned int exec_grade_;

	public:
		Form();
		Form(const std::string, unsigned int sign_grade, unsigned int exec_grade);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};

		const std::string& getName() const;
		bool getIsSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		void beSigned(const Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, Form&);

#endif // FORM_HPP_
