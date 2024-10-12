#include "BitcoinExchange.hpp"
#include <fstream>
#include <typeinfo>

#define S_E_SUCCES					"error of succes"
#define S_E_INSUFFICIENT_ARGUMENTS	"least 2 arg"
// typedef enum e_errors {
// 	E_SUCCES,
// 	E_INSUFFICIENT_ARGUMENTS
// }	t_errors;

// const char* (err_str[]) = {
// 	S_E_SUCCES,
// 	S_E_INSUFFICIENT_ARGUMENTS
// };

// void p_error(t_errors e) {
// 	cerr << err_str[e];
// }

typedef struct t
{
	t() {
		cout << "constructor" << endl;
	};
	void* operator new[](size_t a){
		// cout << a << " " << b << "aaa" << endl;
		return new int;
	}
} t_a;


typedef enum e_column {
	date,
	exchange_rate
}		t_column_idx;

typedef string

typedef float t_price;

int main(int argc, char const *argv[]) try {
	// if (argc != 2)
	// 	throw (runtime_error(S_E_INSUFFICIENT_ARGUMENTS));
	map<string, std::type_info> get_type;
	get_type["date"] = typeid(string);
	get_type["exchange_rate"] = typeid(float);
	
	std::vector<std::type_info> all_types;
	types.push_back(typeid(string));
	types.push_back(typeid(float));
	
	std::ifstream input(argv[1]);
	// t_a g;
	map<string,t_price>* list = new map<t_column_idx, t_value>[3]();
	list[0]["date"] = 123;
	// list[0].at("date") = 123;
	cout << list[0]["date"] << endl;
	// map<string,t_price>** value_by_date = new map<string,t_price>*[10];
	
	return 0;
} catch (runtime_error& e) {
	cerr << e.what() << endl;
}
