#if !defined(GRADETOOLOWEXCEPTION_H)
#define GRADETOOLOWEXCEPTION_H

# include "common.hpp"

class GradeTooLowException: public exception {
	public:
		GradeTooLowException() : msg_(typeid(*this).name()) {}

		/** Constructor (C strings).
		 *  @param message	The error message.
		 *  				the function is explicit to block implicitly cast
		 */
		explicit GradeTooLowException(const char* message) 
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}
		explicit GradeTooLowException(const std::string& message)
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}

		virtual ~GradeTooLowException() throw() {}
		virtual const char* what() const throw() {
			return msg_.c_str();
		}
	protected:
		std::string msg_;

};

#endif // GRADETOOLOWEXCEPTION_H
