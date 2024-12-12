#if !defined(FORM_EXCEPTION_H)
#define FORM_EXCEPTION_H

# include "common.hpp"

class NoSignException: public exception {
	virtual const char* what() const throw() {
		return "NoSignException";
	}
};

#endif // FORM_EXCEPTION_H
