#ifndef SHRUBERRYCREATIONFORM_HPP_
#define SHRUBERRYCREATIONFORM_HPP_

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		ShrubberyCreationForm();

		static const unsigned int GRADE_TO_SIGN = 145;
		static const unsigned int GRADE_TO_EXEC = 137;
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm operator=(const ShrubberyCreationForm&);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const& executor) const;
};

#endif // SHRUBERRYCREATIONFORM_HPP_
