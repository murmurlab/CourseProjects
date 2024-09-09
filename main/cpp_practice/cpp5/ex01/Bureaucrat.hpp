#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include "common.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Form;

class Bureaucrat
{
	private:
		const string	_name;
		int				_grade;
		typedef ::GradeTooHighException GradeTooHighException;
		typedef GradeTooLowException GradeTooLowException;
		Bureaucrat();
	public:
		void			signForm(Form& form);
		void			gradeUp(int grade);
		void			gradeDown(int grade);
		const string&	getName( void );
		int				getGrade( void );
		Bureaucrat(string name, int grade);
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat &operator=(Bureaucrat &assignment);
		~Bureaucrat();
};

ostream& operator<<(ostream& os, Bureaucrat& bro);

#endif
