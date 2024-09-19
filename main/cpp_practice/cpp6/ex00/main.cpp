#include <cmath>
#include <cstdlib>
#include "ScalarConverter.hpp"
#include "common.hpp"
// #include <sanitizer/lsan_interface.h>



int main(int ac, char* av[]) {
// 	string a("inf");
// 	istringstream b("0arstarst");
// 	// int a = dynamic_cast<int>(a);
// 	// float ss = std::nanf;
// 	double c;
// 	b >> c;
// 	cout << c << " " << "arstart" << endl;
// 	cout << (c==__DBL_MAX__) << endl;
// 	char *x;
// 	char str[] = "";
// 	cout << std::strtod("1.7976931348623157e+308", &x) << endl;

// 	// __DBL_MAX__
// 	// 1.7976931348623157e+308
// 	// cout << (void*)(x - str) <<""<< endl;
// 	cout << 1.7976931348623157e+308 / 10 << " tod cevirdi"  << endl;
// 	// (double)__INT_MAX__
// 	// printf("%ld\n", 1.7976931348623157e+308);
// 	// cout.setf(std::ios::fixed, std::ios::floatfield);
// 	// cout.setf(std::ios::showpoint);
// 	// std::cout.precision(std::numeric_limits<long double>::max_exponent10);
// 	// cout.unsetf ( std::ios::floatfield );
// 	// setiosflags(std::ios::fixed);
// 	// printf("%lf aa \n",__DBL_MAX__);
// // __FLT_MAX__

// 	// std::numeric_limits<double>::max_digits10 + 1

// 	cout << "=======" << endl;
// 	cout << trunc(std::strtod("9223372036854775802e1", NULL)) << endl;
// 	cout << std::setprecision(std::numeric_limits<double>::max_digits10 ) << std::defaultfloat <<  (__DBL_MAX__)  << " ------- " << std::strtod("9223372036854775802e1", NULL) << endl; // 1.7976931348623157e+308
// 	cout << trunc(log10(__DBL_MAX__)) << endl;
// 	cout << "=======" << endl;
	// ostringstream in();
	// in << 1.7976931348623157e+308;
	// cout << in.str() << " to string" << endl;
	(void)ac;
	(void)av;

	// string arr[] = {
	//     "words and 2",
	//     "45",
	//     "+45",
	//     " -45",
	//     "3.14159",
	//     "31337 with words",
	//     "12345678901",
	// };
	// int len = (sizeof(arr) / sizeof(string));
	try {
		// ScalarConverter::convert("-0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000002147483647e130");
		cout << static_cast<long>(trunc(2147483500.99f)) << endl;
		// cout << static_cast<int>(trunc(2147483645.0f)) << endl;
		
		ScalarConverter::convert("1");

	} catch (exception& e) {
		cout<< e.what() <<endl;
	}
	// for (size_t i = 0; i < len; i++) {
	// 	// int num(stoi(arr[i]));
	// 	// cout<< num <<endl;
	// }
}

__attribute__((destructor)) void end() {
	// __lsan_do_recoverable_leak_check();
	// __lsan_do_leak_check();
}
