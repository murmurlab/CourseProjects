#if !defined(SCALAR_CONVERTER_H)
#define SCALAR_CONVERTER_H

#include "common.hpp"
#include "ConvertException.hpp"
// #define VAL 2147483647.9991231231231231230e-6f
// #define VAL F2f
#define VAL 4.2e+1

class ScalarConverter {
	private:
		virtual ~ScalarConverter() = 0;
		ScalarConverter();

		static double	_data;
		static char convert_char(string& literal);
		static int convert_int(string& literal);
		static float convert_float(string& literal);
		static double convert_double(string& literal);
		typedef ::ConvertException ConvertException;
	public:
		static void convert(string literal);
};

#endif  // SCALAR_CONVERTER_H
