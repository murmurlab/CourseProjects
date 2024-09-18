#if !defined(SCALAR_CONVERTER_H)
#define SCALAR_CONVERTER_H

#include "common.hpp"

class ScalarConverter {
	private:
		virtual ~ScalarConverter() = 0;
		ScalarConverter();
		string _char;
		string _int;
		string _float;
		string _double;
		void convert_char(string& literal);
		void convert_int(string& literal);
		void convert_float(string& literal);
		void convert_double(string& literal);

	public:
		static void convert(string literal);
};

#endif  // SCALAR_CONVERTER_H
