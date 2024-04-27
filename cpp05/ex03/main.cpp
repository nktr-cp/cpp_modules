#include "Bureaucrat.hpp"
#include "Intern.hpp"

signed main(void) {
	{
		Bureaucrat bureauro("bureauro", 1);
		Intern it;

		AForm* form = it.makeForm("robotomy request", "Bender");
		if (form) {
			bureauro.signForm(*form);
			bureauro.executeForm(*form);
			delete form;
		}
	}
	{
		Bureaucrat bureauro("bureauro", 1);
		Intern it;

		AForm* form = it.makeForm("shrubbery creation", "Bender");
		if (form) {
			bureauro.signForm(*form);
			bureauro.executeForm(*form);
			delete form;
		}
	}
	{
		Bureaucrat bureauro("bureauro", 1);
		Intern it;

		AForm* form = it.makeForm("presidential pardon", "Bender");
		if (form) {
			bureauro.signForm(*form);
			bureauro.executeForm(*form);
			delete form;
		}
	}
	{
		Bureaucrat bureauro("bureauro", 1);
		Intern it;

		AForm* form = it.makeForm("dummy form", "Bender");
		if (form) {
			bureauro.signForm(*form);
			bureauro.executeForm(*form);
			delete form;
		}
	}
}