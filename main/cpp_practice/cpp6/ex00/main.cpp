#include "common.hpp"
#include "ScalarConverter.hpp"
// #include <sanitizer/lsan_interface.h>

int main(int ac, char *av[])
{
    cout<< "arstarst" <<endl;
    (void)ac;
    (void)av;
    // ScalarConverter a;u
    ScalarConverter::convert("");

    const string arr[] = {
        "words and 2",
        "45",
        "+45",
        " -45",
        "3.14159",
        "31337 with words",
        "12345678901",
    };
    const int len = (sizeof(arr)/sizeof(string));

    for (size_t i = 0; i < len; i++)
    {
        // int num(stoi(arr[i]));
        // cout<< num <<endl;
    }
    
}

__attribute__((destructor)) void end() {
    // __lsan_do_recoverable_leak_check();
    // __lsan_do_leak_check();
}
