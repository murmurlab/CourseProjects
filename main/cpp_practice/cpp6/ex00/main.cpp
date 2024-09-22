#include <cmath>
#include <cstdlib>
#include "ScalarConverter.hpp"
#include "common.hpp"

// void	test(string& str) {
// 	double testdb;
// 	istringstream b(str);
// 	b.setf(std::ios_base::scientific, std::ios_base::floatfield);
// 	b >> testdb;
// 	if (!b.good())
// 		std::cerr << "err" << endl;
// 	string my = b.str();

// 	double one = std::strtod(my.c_str(), NULL);
// 	double two = std::strtod(str.c_str(), NULL);
	
// 	cout << "inp						=> " << my << endl
// 		<< ">>double					=> " << testdb << endl << endl

// 		<< "inp strtod()					=> " << two << endl
// 		<< ">>double strtod()				=> " << one << endl << endl

// 		<< ">>double-strtod == >>double			=> " << (one == testdb) << endl
// 		<< "inp-strtod == >>double-strtod			=> " << (one == two) << endl
// 		<< "inp-strtod == >>double				=> " << (two == testdb) << endl << endl

		
// 		<< "static_cast inp-literal				=> " << static_cast<long>((trunc((VAL)))) << endl
// 		<< "static_cast :inp strtod()			=> " << static_cast<long>(trunc(two)) << endl
// 		<< "static_cast >>double				=> " << static_cast<long>(trunc(testdb)) << endl
// 		<< "static_cast :>>double strtod()			=> " << static_cast<long>(trunc(one)) << endl << endl
		
// 		<< "inp-literal == >>double				=> " << (VAL == testdb) << endl
// 		<< "inp-literal == inp-strtod			=> " << (VAL == std::strtod(str.c_str(), NULL)) << endl << endl;
// }

int main(int ac, char* av[]) try {
	// cout.setf(std::ios::fixed, std::ios::floatfield);
	// cout.setf(std::ios::showpoint);
	// setiosflags(std::ios::fixed);
	// std::numeric_limits<double>::max_digits10 + 1
	// double aax=0x.f;
	if (ac != 2) {
		cout << "usage: " << av[0] << " <cpp literal>" << endl;
		cout << "running with default arg" << endl << endl;

		string str(stringify(VAL));
		// test(str);
		ScalarConverter::convert(str.c_str());
		std::exit(1);
	}
	ScalarConverter::convert(av[1]);
} catch (exception& e) {
	cout<< e.what() <<endl;
}
__attribute__((destructor)) void end() {
	// __lsan_do_recoverable_leak_check();
	// __lsan_do_leak_check();
}
