#include "ScalarConverter.hpp"

double ScalarConverter::_data;

char ScalarConverter::convert_char() {
	int	res(convert_int());
	char c = static_cast<char>(res);

	if (res > std::numeric_limits<char>::max() || res < std::numeric_limits<char>::min())
		throw (ConvertException("exceed limitz"));
	if (!std::isprint(c))
		throw (ConvertException("Undisplayable char"));
	return c;
}

int ScalarConverter::convert_int() {
	long casted(_data);

	if (_data != _data)
		throw (ConvertException("impossible integer"));
	if (_data == std::numeric_limits<double>::infinity())
		std::numeric_limits<int>::infinity();
	if (_data == -std::numeric_limits<double>::infinity())
		std::numeric_limits<int>::infinity();
	if (casted > std::numeric_limits<int>::max() ||
		casted < std::numeric_limits<int>::min()) {
			throw (ConvertException("exceded limit"));
	}
	return int(casted);
}

float ScalarConverter::convert_float() {
	return (
		float(_data)
	);
}

double ScalarConverter::convert_double() {
	return _data;
}

void ScalarConverter::convert(string literal) {
	istringstream b(literal);
	b >> _data;
	string my = b.str();

	if (literal.length() == 3 &&
		*literal.begin() == '\'' &&
		(literal.at(literal.length() - 1)) == '\'') {
		_data = (literal.at(1));
	} else {
		char *err;
		_data = std::strtod(literal.c_str(), &err);
		if (*err && !(((*err == 'f' || *err == 'F') && ((literal.find("f") == (literal.length() - 1)) || (literal.find("F") == (literal.length() - 1)))) || (literal == "nanf" || literal == "-nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")))
			throw (ConvertException(string(__PRETTY_FUNCTION__) + " => cannot parse literal: " + *err));
	}
	ostringstream outs;
	outs << "char: ";
	try {
		char res(convert_char());
		outs << "'" <<  res;
		outs << "'" <<  endl;
	}
	catch(ConvertException& e) {
		outs << e.what() << endl;
	}
	outs << "int: ";
	try {
		int res(convert_int());
		outs << res;
		outs << endl;
	}
	catch(ConvertException& e) {
		outs << e.what() << endl;
	}
	outs << "float: "
			<< std::showpoint
			<< std::setprecision(std::numeric_limits<float>::digits10 + 1)
			<< convert_float() << "f" << endl
		<< "double: "
			<< std::showpoint
			<< std::setprecision(std::numeric_limits<double>::digits10 + 1)
			<< convert_double() << endl;
	cout << outs.str();
}

ScalarConverter::~ScalarConverter() {
}
