#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		PresidentialPardonForm();

		static const unsigned int GRADE_TO_SIGN = 25;
		static const unsigned int GRADE_TO_EXEC = 5;
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm operator=(const PresidentialPardonForm&);
		~PresidentialPardonForm();

		void execute(Bureaucrat const& executor) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP_
