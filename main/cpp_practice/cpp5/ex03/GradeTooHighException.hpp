#if !defined(GRADETOOHIGHEXCEPTION_H)
#define GRADETOOHIGHEXCEPTION_H

# include "common.hpp"

class GradeTooHighException: public exception {
	public:
		GradeTooHighException() : msg_(typeid(*this).name()) {}

		/** Constructor (C strings).
		 *  @param message	The error message.
		 *  				the function is explicit to block implicitly cast
		 */
		explicit GradeTooHighException(const char* message) 
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}
		explicit GradeTooHighException(const std::string& message)
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}

		virtual ~GradeTooHighException() throw() {}
		virtual const char* what() const throw() {
			return msg_.c_str();
		}
	protected:
		std::string msg_;
};

#endif // GRADETOOHIGHEXCEPTION_H
