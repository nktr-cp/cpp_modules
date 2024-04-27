#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		RobotomyRequestForm();

		static const unsigned int GRADE_TO_SIGN = 72;
		static const unsigned int GRADE_TO_EXEC = 45;
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		RobotomyRequestForm operator=(const RobotomyRequestForm&);
		~RobotomyRequestForm();

		void execute(Bureaucrat const& executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP_
