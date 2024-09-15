#ifndef AFORM_H
# define AFORM_H

# include "common.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"
# include "FormException.hpp"

class Bureaucrat;

class AForm
{
    protected:
		const string	_name;
		const int		_sign_grade;
		const int		_exec_grade;
		bool			_signature;
		typedef GradeTooHighException GradeTooHighException;
		typedef ::GradeTooLowException GradeTooLowException;
		typedef ::NoSignException NoSignException;
		void validate_grade(int grade, string err);
		void validate_exec(Bureaucrat const & executor) const;
		AForm();
	public:
		string target_;
		AForm(string name, int sign_grade, int exec_grade);
		AForm(AForm &cp);
		AForm& operator=(AForm &assgn);
		virtual ~AForm();
        virtual void execute(Bureaucrat const & executor) const = 0;
		void beSigned(Bureaucrat &bro);
		int getSignGrade();
		int getExecGrade();
		bool getSignature() const;
		const string& getName() const ;
};


ostream& operator<<(ostream& os, AForm& form);

#endif
