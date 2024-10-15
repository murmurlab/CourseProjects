#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[]) try {
	if (argc != 2)
		throw (runtime_error(S_E_INSUFFICIENT_ARGUMENTS));
	
	BitcoinExchange ex;
	ex.calculate(argv[1]);
	
	return 0;
} catch (runtime_error& e) {
	cerr << e.what() << endl;
} catch (...) {
	
}
// !exchange_rate
