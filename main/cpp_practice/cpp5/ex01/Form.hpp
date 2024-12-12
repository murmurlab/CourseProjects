#ifndef FORM_H
# define FORM_H

# include "common.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat;

class Form
{
	private:
		const string	_name;
		const int		_sign_grade;
		const int		_exec_grade;
		bool			_signature;
		typedef GradeTooHighException GradeTooHighException;
		typedef ::GradeTooLowException GradeTooLowException;
		Form();
	public:
		void beSigned(Bureaucrat &bro);
		int getSignGrade();
		int getExecGrade();
		bool getSignature();
		const string& getName();
		Form(string name, int sign_grade, int exec_grade);
		Form(Form &cp);
		Form& operator=(Form &assgn);
		~Form();
};


ostream& operator<<(ostream& os, Form& form);

#endif
