#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("default",  ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXEC)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm(target, ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXEC)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other.getName(), ShrubberyCreationForm::GRADE_TO_SIGN, ShrubberyCreationForm::GRADE_TO_EXEC)
{
	*this = other;
}

ShrubberyCreationForm ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	// name is constant and other values are the same
	// therefore, nothing to copy from other form
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!getIsSigned()) {
		throw AFormNotYetSignedExecption();
	}
	std::string fileName = executor.getName() + "_shrubbery";
	std::ofstream file(fileName);
	if (!file) {
			std::cerr << "Error: Unable to open file " << fileName << std::endl;
			return;
	}

	file << " ________  ___  ___  ________  ___  ___  ________  ________  _______   ________      ___    ___ \n";
	file << "|\\   ____\\|\\  \\|\\  \\|\\   __  \\|\\  \\|\\  \\|\\   __  \\|\\   __  \\|\\  ___ \\ |\\   __  \\    |\\  \\  /  /|\n";
	file << "\\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\|\\ /\\ \\  \\|\\ /\\ \\   __/|\\ \\  \\|\\  \\   \\ \\  \\/  / /\n";
	file << " \\ \\_____  \\ \\   __  \\ \\   _  _\\ \\  \\\\\\  \\ \\   __  \\ \\   __  \\ \\  \\_|/_\\ \\   _  _\\   \\ \\    / / \n";
  file << "  \\|____|\\  \\ \\  \\ \\  \\ \\  \\\\  \\\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\_|\\ \\ \\  \\\\  \\|   \\/  /  /  \n";
  file << "    ____\\_\\  \\ \\__\\ \\__\\ \\__\\\\ _\\\\ \\_______\\ \\_______\\ \\_______\\ \\_______\\ \\__\\\\ _\\ __/  / /    \n";
  file << "   |\\_________\\|__|\\|__|\\|__|\\|__|\\|_______|\\|_______|\\|_______|\\|_______|\\|__|\\|__|\\___/ /     \n";
  file << "   \\|_________|                                                                    \\|___|/ \n";

	file.close();
}
