#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

signed main(void) {
	// AForm form; // this should be an error

	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	{
		PresidentialPardonForm ppf("ppf_test");	

		Bureaucrat bureauro1("bureauro", 1);
		Bureaucrat bureauro2("bureauro", 50);
		Bureaucrat bureauro3("bureauro", 100);

		int exec_idx = -1;
		bureauro3.signForm(ppf);
		if (exec_idx == -1 && ppf.getIsSigned()) {
			exec_idx = 1;
		}
		bureauro2.signForm(ppf);
		if (exec_idx == -1 && ppf.getIsSigned()) {
			exec_idx = 2;
		}
		bureauro1.signForm(ppf);
		if (exec_idx == -1 && ppf.getIsSigned()) {
			exec_idx = 3;
		}

		try{
		switch(exec_idx) {
			case 1:
				bureauro3.executeForm(ppf);
				break;
			case 2:
				bureauro2.executeForm(ppf);
				break;
			case 3:
				bureauro1.executeForm(ppf);
				break;
			default:
				std::cout << "Cannot execute because form " << ppf.getName() << " is not signed" << std::endl;
		}
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	{
		RobotomyRequestForm rrf("rrf_test");

		Bureaucrat bureauro1("bureauro", 1);
		Bureaucrat bureauro2("bureauro", 40);
		Bureaucrat bureauro3("bureauro", 100);

		int exec_idx = -1;
		bureauro3.signForm(rrf);
		if (exec_idx == -1 && rrf.getIsSigned()) {
			exec_idx = 1;
		}
		bureauro2.signForm(rrf);
		if (exec_idx == -1 && rrf.getIsSigned()) {
			exec_idx = 2;
		}
		bureauro1.signForm(rrf);
		if (exec_idx == -1 && rrf.getIsSigned()) {
			exec_idx = 3;
		}

		try {
			switch(exec_idx) {
				case 1:
					bureauro3.executeForm(rrf);
					break;
				case 2:
					bureauro2.executeForm(rrf);
					break;
				case 3:
					bureauro1.executeForm(rrf);
					break;
				default:
					std::cout << "Cannot execute because form " << rrf.getName() << " is not signed" << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	{
		ShrubberyCreationForm scf("scf_test");

		Bureaucrat bureauro1("bureauro", 1);
		Bureaucrat bureauro2("bureauro", 50);
		Bureaucrat bureauro3("bureauro", 100);

		int exec_idx = -1;
		bureauro3.signForm(scf);
		if (exec_idx == -1 && scf.getIsSigned()) {
			exec_idx = 1;
		}
		bureauro2.signForm(scf);
		if (exec_idx == -1 && scf.getIsSigned()) {
			exec_idx = 2;
		}
		bureauro1.signForm(scf);
		if (exec_idx == -1 && scf.getIsSigned()) {
			exec_idx = 3;
		}

		try {
			switch(exec_idx) {
				case 1:
					bureauro3.executeForm(scf);
					break;
				case 2:
					bureauro2.executeForm(scf);
					break;
				case 3:
					bureauro1.executeForm(scf);
					break;
				default:
					std::cout << "Cannot execute because form " << scf.getName() << " is not signed" << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	{
		PresidentialPardonForm ppf("ppf_test");	

		Bureaucrat bureauro1("bureauro", 130);
		Bureaucrat bureauro2("bureauro", 140);
		Bureaucrat bureauro3("bureauro", 150);

		int exec_idx = -1;
		bureauro3.signForm(ppf);
		if (exec_idx == -1 && ppf.getIsSigned()) {
			exec_idx = 1;
		}
		bureauro2.signForm(ppf);
		if (exec_idx == -1 && ppf.getIsSigned()) {
			exec_idx = 2;
		}
		bureauro1.signForm(ppf);
		if (exec_idx == -1 && ppf.getIsSigned()) {
			exec_idx = 3;
		}

		try {
			switch(exec_idx) {
				case 1:
					bureauro3.executeForm(ppf);
					break;
				case 2:
					bureauro2.executeForm(ppf);
					break;
				case 3:
					bureauro1.executeForm(ppf);
					break;
				default:
					std::cout << "Cannot execute because form " << ppf.getName() << " is not signed" << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
