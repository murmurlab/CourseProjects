#if !defined(ROBOTOMY_REQUEST_FORM_H)
#define ROBOTOMY_REQUEST_FORM_H

# include "common.hpp"
# include "AForm.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(string target);
		RobotomyRequestForm(AForm &cp);
		RobotomyRequestForm& operator=(AForm &assgn);
		~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};

#endif // ROBOTOMY_REQUEST_FORM_H
