#if !defined(GRADETOOLOWEXCEPTION_H)
#define GRADETOOLOWEXCEPTION_H

# include "common.hpp"

class GradeTooLowException: public exception {
	virtual const char* what() const throw() {
		return "GradeTooLowException";
	}
};

#endif // GRADETOOLOWEXCEPTION_H
