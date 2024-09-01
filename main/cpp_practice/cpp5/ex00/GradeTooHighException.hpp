#if !defined(GRADETOOHIGHEXCEPTION_H)
#define GRADETOOHIGHEXCEPTION_H

# include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException: public exception {
	virtual const char* what() const throw() {
		return "Grade limit exceeded";
	}
};

#endif // GRADETOOHIGHEXCEPTION_H
