#if !defined(GRADETOOHIGHEXCEPTION_H)
#define GRADETOOHIGHEXCEPTION_H

# include "common.hpp"

class GradeTooHighException: public exception {
	virtual const char* what() const throw() {
		return "GradeTooHighException";
	}
};

#endif // GRADETOOHIGHEXCEPTION_H
