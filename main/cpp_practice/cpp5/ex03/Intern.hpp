#ifndef INTERN_H
# define INTERN_H

# include "common.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"
# include "FormException.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define FORM_COUNT 3

class Intern
{
    protected:
		typedef GradeTooHighException GradeTooHighException;
		typedef ::GradeTooLowException GradeTooLowException;
		typedef ::NoSignException NoSignException;
		void validate_grade(int grade, string err);
	public:
        static const string form_names[FORM_COUNT];
        static AForm* (*form_constructors[FORM_COUNT])(string);
        AForm* makeForm(string form_name, string target_of_form);
		Intern();
		Intern(Intern &cp);
		Intern& operator=(Intern &assgn);
		~Intern();
};

ostream& operator<<(ostream& os, Intern& form);

#endif
