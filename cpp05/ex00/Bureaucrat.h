#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <string>

class Bureaucrat {
	private:
		static const unsigned int maxgrade_ = 1;
		static const unsigned int mingrade_ = 150;

		const std::string name_;
		unsigned int grade_;

	public:
		Bureaucrat();

		Bureaucrat(const std::string, unsigned int);

		Bureaucrat(const Bureaucrat&);

		Bureaucrat& operator=(const Bureaucrat&);

		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void incrementGrade();
		void decrementGrade();
		const std::string& getName() const;
		unsigned int getGrade() const;
};

std::ostream& operator<<(std::ostream&, Bureaucrat&);

#endif // BUREAUCRAT_H_