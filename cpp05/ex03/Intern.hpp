#ifndef INTERN_HPP_
#define INTERN_HPP_

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		AForm* makePresidentialPardonForm(std::string);
		AForm* makeRobotomyRequestForm(std::string);
		AForm* makeShrubberyCreationForm(std::string);
	public:
		Intern();
		Intern(const Intern&);
		Intern operator=(const Intern&);
		~Intern();

		AForm* makeForm(std::string form_name, std::string target_form);
};

#endif // INTERN_HPP_