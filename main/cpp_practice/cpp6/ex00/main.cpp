#include <cmath>
#include <cstdlib>
#include "ScalarConverter.hpp"
#include "common.hpp"
// #include <sanitizer/lsan_interface.h>

int main(int ac, char* av[]) {
	int a = {2};
	// float ss = std::nanf;
	cout << std::strtof("nala", NULL) << endl;
	(void)ac;
	(void)av;
	string arr[] = {
	    "words and 2",
	    "45",
	    "+45",
	    " -45",
	    "3.14159",
	    "31337 with words",
	    "12345678901",
	};
	int len = (sizeof(arr) / sizeof(string));
	ScalarConverter::convert("");
	for (size_t i = 0; i < len; i++) {
		// int num(stoi(arr[i]));
		// cout<< num <<endl;
	}
}

__attribute__((destructor)) void end() {
	// __lsan_do_recoverable_leak_check();
	// __lsan_do_leak_check();
}
