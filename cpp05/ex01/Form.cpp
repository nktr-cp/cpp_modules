#include "Form.hpp"

Form::Form()
:	name_("default"),
	is_signed_(false),
	sign_grade_(100),
	exec_grade_(100)
{}

Form::Form(const std::string name, unsigned int sign_grade, unsigned int exec_grade)
: name_(name),
	is_signed_(false),
	sign_grade_(sign_grade),
	exec_grade_(exec_grade)
{
	if (sign_grade < Form::MAXGRADE) {
		throw GradeTooHighException();
	} else if (sign_grade > Form::MINGRADE) {
		throw GradeTooLowException();
	}
	if (exec_grade < Form::MAXGRADE) {
		throw GradeTooHighException();
	} else if (exec_grade > Form::MINGRADE) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form& other)
: name_(other.getName()),
	sign_grade_(other.getSignGrade()),
	exec_grade_(other.getExecGrade())
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this == &other) {
		return *this;
	}

	this->is_signed_ = other.is_signed_;
	return *this;
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}

const char* Form::FormAlreadySignedException::what() const throw() {
	return "Form already signed!";
}

const std::string& Form::getName() const {
	return this->name_; 
}

bool Form::getIsSigned() const {
	return this->is_signed_;
}

unsigned int Form::getSignGrade() const {
	return this->sign_grade_;
}

unsigned int Form::getExecGrade() const {
	return this->exec_grade_;
}

void Form::beSigned(const Bureaucrat& b) {
	if (this->is_signed_) {
		throw FormAlreadySignedException();
	} else if (b.getGrade() > this->getSignGrade()) {
		throw GradeTooLowException();
	}
	this->is_signed_ = true;
}

std::ostream& operator<<(std::ostream& os, Form& a) {
	os << std::setw(28) << std::left << "Bureaucrat name" << ": " << a.getName() << std::endl;
	os << std::setw(28) << std::left << "Grade required to sign" << ": " << a.getSignGrade() << std::endl;
	os << std::setw(28) << std::left << "Grade required to execute" << ": " << a.getExecGrade() << std::endl;
	os << std::setw(28) << std::left <<  "Signed or not signed" << ": " << (a.getIsSigned() ? "already signed." : "not signed yet.");
	return os;
}
