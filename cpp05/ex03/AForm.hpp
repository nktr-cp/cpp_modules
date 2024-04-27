#ifndef AFORM_HPP_
#define AFORM_HPP_

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class AForm {
	private:
		static const unsigned int MAXGRADE = 1;
		static const unsigned int MINGRADE = 150;

		const std::string name_;
		bool is_signed_;
		const unsigned int sign_grade_;
		const unsigned int exec_grade_;
	
	protected:
		std::string target_;

	public:
		AForm();
		AForm(const std::string, unsigned int sign_grade, unsigned int exec_grade);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class AFormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};


		class AFormNotYetSignedExecption : public std::exception {
			public:
				const char* what() const throw();
		};

		const std::string& getName() const;
		bool getIsSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		std::string getTarget() const;

		void beSigned(const Bureaucrat&);

		virtual void execute(Bureaucrat const&) const = 0;
};

std::ostream& operator<<(std::ostream&, AForm&);

#endif // AFORM_HPP_
