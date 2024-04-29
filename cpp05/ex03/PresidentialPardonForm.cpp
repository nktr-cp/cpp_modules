#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm",  PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXEC)
{
	target_ = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXEC)
{
	target_ = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm("PresidentialPardonForm", PresidentialPardonForm::GRADE_TO_SIGN, PresidentialPardonForm::GRADE_TO_EXEC)
{
	*this = other;
}

PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	// name is constant and other values are the same
	// therefore, nothing to copy from other form
	this->target_ = other.target_;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		throw AFormNotYetSignedExecption();
	} else if (executor.getGrade() > PresidentialPardonForm::GRADE_TO_EXEC) {
		throw GradeTooHighException();
	}

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
