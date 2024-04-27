#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("default",  PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXEC)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm(target, PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXEC)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other.getName(), PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXEC)
{
	*this = other;
}

PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	// name is constant and other values are the same
	// therefore, nothing to copy from other form
	(void)other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		throw AFormNotYetSignedExecption();
	}

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
