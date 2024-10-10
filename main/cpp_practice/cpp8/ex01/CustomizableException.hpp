#if !defined(CUSTOMIZABLE_EXCEPTION_HPP)
# define CUSTOMIZABLE_EXCEPTION_HPP

# include "common.hpp"

class CustomizableException: public exception {
	public:
		CustomizableException() : msg_(typeid(*this).name()) {}

		/** Constructor (C strings).
		 *  @param message	The error message.
		 *  				the function is explicit to block implicitly cast
		 */
		explicit CustomizableException(const char* message) 
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}
		explicit CustomizableException(const std::string& message)
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}

		virtual ~CustomizableException() throw() {}
		virtual const char* what() const throw() {
			return msg_.c_str();
		}
	protected:
		std::string msg_;

};

#endif // CUSTOMIZABLE_EXCEPTION_HPP
