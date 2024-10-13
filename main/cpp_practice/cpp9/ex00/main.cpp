#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <iterator>
#include <ostream>
#include <iomanip>

#define DISCRIMINATOR_1				','
#define DISCRIMINATOR_2				'|'

#define DEFAULT_CSV_FILE			"./data.csv"

#define S_E_SUCCES					"error of succes"
#define S_E_INSUFFICIENT_ARGUMENTS	"least 2 arg"
#define S_E_CANNOT_OPEN_FILE		"cannot open file"
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

// typedef struct t
// {
// 	t() {
// 		cout << "constructor" << endl;
// 	};
// 	void* operator new[](size_t a){
// 		// cout << a << " " << b << "aaa" << endl;
// 		return new int;
// 	}
// } t_a;

typedef enum e_column {
	date = 0, // string
	exchange_rate, // float
	unknown_type
}		t_column_idx;

// 1typedef string

typedef float t_price;
// typedef void*(ar)[3];

void*	new_Date(void* data) {
	time_t* time = new time_t;
	
    // Initialize a tm structure to hold the parsed date
    tm tm = {};

    // Create a string stream to parse the date string
    std::istringstream ss(string((char *)data));

    // Parse the date string using std::get_time
    ss >> std::strptime(&tm, "%Y-%m-%d");

    // Check if parsing was successful
    if (ss.fail()) {
        cout << "Date parsing failed!" << endl;
	*time = mktime(&tm);
	return (time);
}

void*	new_ExchangeRate(void* data) {
	float a;
	std::istringstream iss((char *)data);
	iss >> a;
	if (iss.fail())
		return (NULL);
	float* exchange = new float(a);
	return (exchange);
}

void*	new_Unknown(void* data) {
	void* ret = NULL;
	return (ret);
}

void*	serialize(t_column_idx type, char* data) {
	void* (*jmp_table[3])(void* data) = {
		new_Date,
		new_ExchangeRate,
		new_Unknown
	};
	return (jmp_table[type](data));
}

int main(int argc, char const *argv[]) try {
	if (argc != 2)
		throw (runtime_error(S_E_INSUFFICIENT_ARGUMENTS));
	// map<string, std::type_info> get_type;
	// get_type["date"] = typeid(string);
	// get_type["exchange_rate"] = typeid(float);

	// std::vector<std::type_info> all_types;
	// types.push_back(typeid(string));
	// types.push_back(typeid(float));
	
	std::ifstream infile(DEFAULT_CSV_FILE);
	if (!infile) throw(runtime_error(S_E_CANNOT_OPEN_FILE));
	std::ostringstream content;
	content << infile.rdbuf();
	string all(content.str());

	std::istringstream readable(all);

	size_t rows = std::count(all.begin(), all.end(), '\n');
	size_t coloumns = 2;
	cout << rows << endl;	
	string line;
	std::getline(readable, line);
	cout << line << endl;
	
	std::vector<t_column_idx> coloumn_types;
	std::istringstream iss(line.c_str());
	for (char node[44]; iss.getline(node, 44, DISCRIMINATOR_1);) {
		coloumn_types.push_back(
			(node == string("date")) ?			date :
			(node == string("exchange_rate")) ?	exchange_rate :
												unknown_type
		);
		cout << "\t" << node << endl;
		cout << "\t\t typedef " << node << " " << coloumn_types.back() << endl;
	}
	std::vector<void*> table(coloumns * rows);
	table[(399 * coloumns) + 1] = NULL;

	for (size_t row(0); std::getline(readable, line); row++) {
		cout << line << endl;
		std::istringstream iss_tmp(line.c_str());
		int col = coloumn_types.front();
		for (char node[44]; iss_tmp.getline(node, 44, DISCRIMINATOR_1); col++) {
			cout << "\t" << "<" << coloumn_types[col] << ">" << node << endl;
			

			// (coloumn_types[col] == date) ?			("NULL") :
			// (coloumn_types[col] == exchange_rate) ?	(NULL) :
			// 											(NULL)
		
			table[(row * coloumns) + col] = serialize(coloumn_types[col] ,node);
			// if 
			// table[(row * coloumns) + col] = NULL;
		}
		
		break;
	}
	
	// delete table[(row * coloumns) + col];
	
	// std:;getline(all)
	
	// t_a g;
	// map<string,t_price>* list = new map<t_column_idx, t_value>[3]();
	// list[0]["date"] = 123;
	// list[0].at("date") = 123;
	// cout << list[0]["date"] << endl;
	// map<string,t_price>** value_by_date = new map<string,t_price>*[10];
	
	return 0;
} catch (runtime_error& e) {
	cerr << e.what() << endl;
}
