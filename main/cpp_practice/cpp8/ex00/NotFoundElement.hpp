#if !defined(NOT_FOUND_ELEMENT_HPP)
# define NOT_FOUND_ELEMENT_HPP

# include "common.hpp"

class NotFoundElement: public exception {
	public:
		NotFoundElement() : msg_(typeid(*this).name()) {}

		/** Constructor (C strings).
		 *  @param message	The error message.
		 *  				the function is explicit to block implicitly cast
		 */
		explicit NotFoundElement(const char* message) 
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}
		explicit NotFoundElement(const std::string& message)
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}

		virtual ~NotFoundElement() throw() {}
		virtual const char* what() const throw() {
			return msg_.c_str();
		}
	protected:
		std::string msg_;

};

#endif // NOT_FOUND_ELEMENT_HPP
