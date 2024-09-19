#if !defined(CONVERT_EXCEPTION_H)
#define CONVERT_EXCEPTION_H

# include "common.hpp"

class ConvertException: public exception {
	public:
		ConvertException() : msg_(typeid(*this).name()) {}

		/** Constructor (C strings).
		 *  @param message	The error message.
		 *  				the function is explicit to block implicitly cast
		 */
		explicit ConvertException(const char* message) 
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}
		explicit ConvertException(const std::string& message)
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}

		virtual ~ConvertException() throw() {}
		virtual const char* what() const throw() {
			return msg_.c_str();
		}
	protected:
		std::string msg_;
};

#endif // CONVERT_EXCEPTION_H
