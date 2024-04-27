#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makePresidentialPardonForm(std::string target_name) {
	return (new PresidentialPardonForm(target_name));
}

AForm* Intern::makeRobotomyRequestForm(std::string target_name) {
	return (new RobotomyRequestForm(target_name));
}

AForm* Intern::makeShrubberyCreationForm(std::string target_name) {
	return (new ShrubberyCreationForm(target_name));
}

AForm* Intern::makeForm(std::string form_name, std::string target_form) {
	const std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (Intern::*func[])(std::string) = {&Intern::makePresidentialPardonForm, &Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm};

	for (size_t i=0; i<sizeof(formNames) / sizeof(std::string); ++i) {
		if (form_name.compare(formNames[i]) == 0) {
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (this->*func[i])(target_form);
		}
	}

	std::cout << "No forms match the argument" << std::endl;
	return NULL;
}
