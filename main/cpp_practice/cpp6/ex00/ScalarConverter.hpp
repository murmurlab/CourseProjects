#if !defined(SCALAR_CONVERTER_H)
#define SCALAR_CONVERTER_H

#include "common.hpp"
#include "ConvertException.hpp"

class ScalarConverter {
	private:
		virtual ~ScalarConverter() = 0;
		ScalarConverter();

		static double	_data;
		static string convert_char(string& literal);
		static string convert_int(string& literal);
		static string convert_float(string& literal);
		static string convert_double(string& literal);
		typedef ::ConvertException ConvertException;
	public:
		static void convert(string literal);
};

#endif  // SCALAR_CONVERTER_H
