#include "ScalarConverter.hpp"

double ScalarConverter::_data;

string ScalarConverter::convert_char(string& literal) {
	return ("");
}

string ScalarConverter::convert_int(string& literal) {
	// 1.7976931348623157e+308
	// cout << endl << trunc(_data) << endl;
	if ((trunc(_data)) > ((double)std::numeric_limits<int>::max()) || 
		(trunc(_data)) < ((double)std::numeric_limits<int>::min())) {
		return ("imp");
	} else {
		ostringstream in;
		in << std::setprecision(std::numeric_limits<double>::digits10) << trunc(_data);
		return in.str();		
	}
	// cout << trunc(log10(_data)) << endl;
	return ("");
}

string ScalarConverter::convert_float(string& literal) {
	
	return ("");
	
}

string ScalarConverter::convert_double(string& literal) {
	ostringstream in;
	in << std::setprecision(std::numeric_limits<double>::digits10) << _data;
	return (
		in.str()
	);
}

void ScalarConverter::convert(string literal) {
	// cout << (literal.back()) << endl
	// 	<< *literal.begin() << endl
	// 	<< literal.length() << endl;
	if (literal.length() == 3 &&
		*literal.begin() == '\'' &&
		(literal.at(literal.length() - 1)) == '\'') {
		// cout << literal.at(1) << " <-" << endl;
		_data = (literal.at(1));
		return ;
	}
	char *err;
	_data = std::strtod(literal.c_str(), &err);
	if (*err)
		throw (ConvertException(string(__PRETTY_FUNCTION__) + " => cannot parse number"));
	cout << "char: " << convert_char(literal) << endl
		<< "int: " << convert_int(literal) << endl
		<< "float: " << convert_float(literal) << endl
		<< "double: " << convert_double(literal) << endl;
}

ScalarConverter::~ScalarConverter() {
}
