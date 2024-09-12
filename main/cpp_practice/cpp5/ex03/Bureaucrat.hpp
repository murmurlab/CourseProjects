#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include "common.hpp"
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class AForm;

class Bureaucrat
{
	private:
		const string	_name;
		int				_grade;
		typedef ::GradeTooHighException GradeTooHighException;
		typedef GradeTooLowException GradeTooLowException;
		Bureaucrat();
	public:
		Bureaucrat(string name, int grade);
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat &operator=(Bureaucrat &assignment);
		~Bureaucrat();
		void			validate_grade(int grade, string err);
		void			executeForm(AForm const & form) const ;
		void			signForm(AForm& form);
		void			gradeUp(int grade);
		void			gradeDown(int grade);
		const string&	getName( void );
		int				getGrade( void ) const;
};

ostream& operator<<(ostream& os, Bureaucrat& bro);

#endif
