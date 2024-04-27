#include "AForm.hpp"

AForm::AForm()
:	name_("default"),
	is_signed_(false),
	sign_grade_(100),
	exec_grade_(100)
{}

AForm::AForm(const std::string name, unsigned int sign_grade, unsigned int exec_grade)
: name_(name),
	is_signed_(false),
	sign_grade_(sign_grade),
	exec_grade_(exec_grade)
{
	if (sign_grade < AForm::MAXGRADE) {
		throw GradeTooHighException();
	} else if (sign_grade > AForm::MINGRADE) {
		throw GradeTooLowException();
	}
	if (exec_grade < AForm::MAXGRADE) {
		throw GradeTooHighException();
	} else if (exec_grade > AForm::MINGRADE) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& other)
: name_(other.getName()),
	sign_grade_(other.getSignGrade()),
	exec_grade_(other.getExecGrade())
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other) {
		return *this;
	}

	this->is_signed_ = other.is_signed_;
	return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm grade too low!";
}

const char* AForm::AFormAlreadySignedException::what() const throw() {
	return "AForm already signed!";
}

const char* AForm::AFormNotYetSignedExecption::what() const throw() {
	return "AForm is not signed yet!";
}

const std::string& AForm::getName() const {
	return this->name_; 
}

bool AForm::getIsSigned() const {
	return this->is_signed_;
}

unsigned int AForm::getSignGrade() const {
	return this->sign_grade_;
}

unsigned int AForm::getExecGrade() const {
	return this->exec_grade_;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (this->is_signed_) {
		throw AFormAlreadySignedException();
	} else if (b.getGrade() > this->getSignGrade()) {
		throw GradeTooLowException();
	}
	this->is_signed_ = true;
}

std::ostream& operator<<(std::ostream& os, AForm& a) {
	os << std::setw(28) << std::left << "Bureaucrat name" << ": " << a.getName() << std::endl;
	os << std::setw(28) << std::left << "Grade required to sign" << ": " << a.getSignGrade() << std::endl;
	os << std::setw(28) << std::left << "Grade required to execute" << ": " << a.getExecGrade() << std::endl;
	os << std::setw(28) << std::left <<  "Signed or not signed" << ": " << (a.getIsSigned() ? "already signed." : "not signed yet.");
	return os;
}
