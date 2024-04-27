#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm",  RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXEC)
{
	target_ = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXEC)
{
	target_ = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm("RobotomyRequestForm", RobotomyRequestForm::GRADE_TO_SIGN, RobotomyRequestForm::GRADE_TO_EXEC)
{
	*this = other;
}

RobotomyRequestForm RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	// name is constant and other values are the same
	// therefore, nothing to copy from other form
	this->target_ = other.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		throw AFormNotYetSignedExecption();
	} else if (executor.getGrade() > RobotomyRequestForm::getExecGrade()) {
		throw GradeTooLowException();
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
