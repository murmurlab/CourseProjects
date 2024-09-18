#include "ScalarConverter.hpp"

void ScalarConverter::convert_char(string& literal) {
}

void ScalarConverter::convert_int(string& literal) {
}

void ScalarConverter::convert_float(string& literal) {
}

void ScalarConverter::convert_double(string& literal) {}

void ScalarConverter::convert(string literal) {
	if (*literal.begin() == '\'' && *literal.end() == '\'')
		cout << literal << endl;
}

ScalarConverter::~ScalarConverter() {
}
