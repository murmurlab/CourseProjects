#if !defined(PRESIDENTIAL_PARDON_FORM_H)
#define PRESIDENTIAL_PARDON_FORM_H

# include "common.hpp"
# include "AForm.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(string target);
		PresidentialPardonForm(AForm &cp);
		PresidentialPardonForm& operator=(AForm &assgn);
		~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
};

#endif // PRESIDENTIAL_PARDON_FORM_H
