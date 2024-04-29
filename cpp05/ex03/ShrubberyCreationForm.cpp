#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm",  ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXEC)
{
	this->target_ = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXEC)
{
	this->target_ = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm("ShrubberyCreationForm", ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXEC)
{
	*this = other;
}

ShrubberyCreationForm ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	this->target_ = other.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		throw AFormNotYetSignedExecption();
	} else if (executor.getGrade() > ShrubberyCreationForm::GRADE_TO_EXEC) {
		throw GradeTooHighException();
	}
	
	std::string fileName = executor.getName() + "_shrubbery";
	std::ofstream file(fileName);
	if (!file) {
			std::cerr << "Error: Unable to open file " << fileName << std::endl;
			return;
	}

	file << "                   /^\\\n";
	file << "                  /\\   /\\\n";
	file << "                 /\\/\\_/\\/\\\n";
	file << "                /\\/\\_/\\_/\\/\\\n";
	file << "               /\\/\\_/\\_/\\_/\\/\\\n";
	file << "              /\\/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "             /\\/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "            /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "           /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "          /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "         /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "        /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "       /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "      /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "     /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "    /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "   /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "  /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << " /\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "------------------------------------------------------\n";

	file << "                     /^\\\n";
	file << "            /\\      /\\   /\\\n";
	file << "           /\\/\\    /\\/\\_/\\/\\\n";
	file << "          /\\/\\/\\  /\\/\\_/\\_/\\/\\\n";
	file << "         /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\/\\\n";
	file << "        /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "       /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "      /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "     /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "    /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "   /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "  /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << " /\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "/\\/\\/\\/\\/\\/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\/\\\n";
	file << "---------------------------------------\n";

	file.close();
}
