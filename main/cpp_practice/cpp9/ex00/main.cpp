#include "BitcoinExchange.hpp"
#include <fstream>

#define S_E_SUCCES					"error of succes"
#define S_E_INSUFFICIENT_ARGUMENTS	"least 2 arg"
typedef enum e_errors {
	E_SUCCES,
	E_INSUFFICIENT_ARGUMENTS
}	t_errors;

char* (err_str[]) = {
	"S_E_SUCCES",
	S_E_INSUFFICIENT_ARGUMENTS
};

void p_error(t_errors e) {
	cerr << 
}

int main(int argc, char const *argv[]) try {
	if (argc != 2)
		throw (INSUFFICIENT_ARGUMENTS);
	std::ifstream input(argv[1]);
	
	(void)(argc + argv);
	
	return 0;
} catch (t_errors e) {
	p_error(e);
}
