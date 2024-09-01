#if !defined(GRADETOOLOWEXCEPTION_H)
#define GRADETOOLOWEXCEPTION_H

# include "Bureaucrat.hpp"

class Bureaucrat::GradeTooLowException: public exception {
	virtual const char* what() const throw() {
		return "Grade limit exceeded";
	}
};

#endif // GRADETOOLOWEXCEPTION_H
