#if !defined(ARRAY_EXCEED_INDEX_EXCEPTION_HPP)
# define ARRAY_EXCEED_INDEX_EXCEPTION_HPP

# include "common.hpp"

class ArrayExceedIndexException: public exception {
	public:
		ArrayExceedIndexException() : msg_(typeid(*this).name()) {}

		/** Constructor (C strings).
		 *  @param message	The error message.
		 *  				the function is explicit to block implicitly cast
		 */
		explicit ArrayExceedIndexException(const char* message) 
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}
		explicit ArrayExceedIndexException(const std::string& message)
			: msg_(string(typeid(*this).name()) + ": " + string(message)) {}

		virtual ~ArrayExceedIndexException() throw() {}
		virtual const char* what() const throw() {
			return msg_.c_str();
		}
	protected:
		std::string msg_;

};

#endif // ARRAY_EXCEED_INDEX_EXCEPTION_HPP
