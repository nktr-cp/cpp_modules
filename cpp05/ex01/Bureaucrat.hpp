#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <string>

class Form;

class Bureaucrat {
	private:
		static const unsigned int MAXGRADE = 1;
		static const unsigned int MINGRADE = 150;

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

		// note:
		// Since grade 1 is the highest one and 150 the lowest,
		// incrementing a grade 3 should give a grade 2 to the bureaucrat.
		void incrementGrade();
		void decrementGrade();
		const std::string& getName() const;
		unsigned int getGrade() const;

		void signForm(Form&) const;
};

std::ostream& operator<<(std::ostream&, Bureaucrat&);

#endif // BUREAUCRAT_HPP_
