#include "ScalarConverter.hpp"

void    ScalarConverter::convert_char(string &literal) {
    (void)literal;
}

void    ScalarConverter::convert_int(string &literal) {
    (void)literal;

}

void    ScalarConverter::convert_float(string &literal) {
    (void)literal;

}

void    ScalarConverter::convert_double(string &literal) {
    (void)literal;

}


void ScalarConverter::convert(string literal) {
    // std::thread a;
    // regex r("");
    if (*literal.begin() == '\'' && *literal.end() == '\'')
    cout<< literal <<endl;
}

ScalarConverter::~ScalarConverter() {

}
