#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("default",  RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXEC)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm(target, RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXEC)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other.getName(), RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXEC)
{
	*this = other;
}

RobotomyRequestForm RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	// name is constant and other values are the same
	// therefore, nothing to copy from other form
	(void)other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		throw AFormNotYetSignedExecption();
	}
	// drilling noises
	std::cout << "Rrrrrrrrrrrrrrrrrrrrr......" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2) {
		std::cout << executor.getName() << " has successfully been robotomized!" << std::endl;
	} else {
		std::cout << "Robotomizing " << executor.getName() << " ended in failure..." << std::endl;
	}
}
