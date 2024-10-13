#include "BitcoinExchange.hpp"


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

// void*	new_Date(void* data) {
// 	t_date* data_str = new t_date((char *)data);
// 	return (data_str);
// }

// void*	new_ExchangeRate(void* data) {
// 	t_exchange_rate a;
// 	std::istringstream iss((char *)data);
// 	iss >> a;
// 	if (iss.fail())
// 		return (NULL);
// 	t_exchange_rate* exchange = new t_exchange_rate(a);
// 	return (exchange);
// }

// void*	new_Unknown(void* data) {
// 	void* ret = NULL;
// 	return (ret);
// }

// void*	serialize(t_column_idx type, char* data) {
// 	void* (*jmp_table[3])(void* data) = {
// 		new_Date,
// 		new_ExchangeRate,
// 		new_Unknown
// 	};
// 	return (jmp_table[type](data));
// }



// t_csv	to_table(std::ifstream& csv_file, char seperator = ',') {
// 	t_csv t;

// 	std::ostringstream content;
// 	content << csv_file.rdbuf();
// 	string all(content.str());
// 	std::istringstream readable(all);

// 	t.height = std::count(all.begin(), all.end(), '\n');
// 	cout << t.height << endl;	

// 	string line;
// 	std::getline(readable, line);
// 	cout << line << endl;
	
// 	t.column_types = new std::vector<t_column_idx>;
// 	std::istringstream iss(line.c_str());
// 	size_t l = line.length(); 
// 	char* node = new char[l];
// 	for (; iss.getline(node, l, seperator);) {
// 		string untrimmed(node);
// 		string trimmed;
// 		std::istringstream str(untrimmed);
// 		str >> trimmed;
// 		// cout << trimmed << endl;
// 		t.column_types->push_back(
// 			(trimmed == string("date")) ?			date :
// 			(trimmed == string("value")) ?			value :
// 			(trimmed == string("exchange_rate")) ?	exchange_rate :
// 												unknown_type
// 		);
// 		cout << "\t" << trimmed << endl;
// 		cout << "\t\t typedef " << trimmed << " " << t.column_types->back() << endl;
// 	}
// 	t.width = t.column_types->size();
// 	t.c = new std::vector<void*>(t.width * t.height);
// 	// table[(399 * coloumns) + 1] = NULL;

// 	for (size_t row(0); std::getline(readable, line); row++) {
// 		cout << line << endl;
// 		std::istringstream iss_tmp(line.c_str());
// 		int col = t.column_types->front();
// 		size_t le = line.length();
// 		char* node = new char[le];
		
// 		bool cont = true;
// 		for (; cont; col++) {
// 			cont = iss_tmp.getline(node, le, seperator);

// 			if (!cont)
// 				t.c->at((row * t.width) + col) = NULL;
// 			else {
// 				// (coloumn_types[col] == date) ?			("NULL") :
// 				// (coloumn_types[col] == exchange_rate) ?	(NULL) :
// 				// 											(NULL)
// 				string untrimmed(node);
// 				string trimmed;
// 				std::istringstream str(untrimmed);
// 				str >> trimmed;
// 				cout << "\t" << "<" << t.column_types->at(col) << ">" << trimmed << endl;
// 				t.c->at((row * t.width) + col) = serialize(t.column_types->at(col) ,(char *)trimmed.c_str());
// 			}
// 			// if 
// 			// table[(row * coloumns) + col] = NULL;
// 		}
// 	}
// 	return t;
// }

// t_row select_y(t_csv const& table, size_t column, void* value){
// 	if (column > table.width || column < 0)
// 		return NULL;
// 	for (size_t i = 0; i < table.height - 1; i++) {
// 		// for (size_t j = 0; j < table.width; j++) {
// 		// }
// 		if (date == table.column_types->at(column))
// 		{
// 			// cout << "date" << endl;
// 			// (table.c->at((i * table.width) + column))
// 			// if (!table.c->at((i * table.width) + column))
				
// 			if (*((t_date *)table.c->at((i * table.width) + column)) == *(t_date *)value)
// 			{
// 				void** row= new void*[table.width];
// 				for (size_t col = 0; col < table.width; col++)
// 					row[col] = table.c->at((i * table.width) + col);
// 				return row;
// 			}
// 		}
// 		else if (exchange_rate == table.column_types->at(column))
// 		{
// 			if (*((t_exchange_rate *)table.c->at((i * table.width) + column)) == *(t_exchange_rate *)value)
// 			{
// 				void** row= new void*[table.width];
// 				for (size_t col = 0; col < table.width; col++)
// 					row[col] = table.c->at((i * table.width) + col);
// 				return row;
// 			}
// 		}
// 		else if (unknown_type == table.column_types->at(column))
// 		{
// 			if (table.c->at((i * table.width) + column) == value)
// 			{
// 				void** row= new void*[table.width];
// 				for (size_t col = 0; col < table.width; col++)
// 					row[col] = table.c->at((i * table.width) + col);
// 				return row;
// 			}
// 		}

// 	}
// }


int main(int argc, char const *argv[]) try {
	if (argc != 2)
		throw (runtime_error(S_E_INSUFFICIENT_ARGUMENTS));
	
	BitcoinExchange ex;
	ex.calculate(argv[1]);
	// map<string, std::type_info> get_type;
	// get_type["date"] = typeid(string);
	// get_type["exchange_rate"] = typeid(float);

	// std::vector<std::type_info> all_types;
	// types.push_back(typeid(string));
	// types.push_back(typeid(float));
	// std::ifstream db_file(DEFAULT_CSV_FILE);
	// std::ifstream infile(argv[1]);

	// cout << infile.rdbuf();
	
	// if (!db_file || !infile) throw(runtime_error(S_E_CANNOT_OPEN_FILE));
	// t_csv table = to_table(db_file);
	// t_csv inp = to_table(infile, '|');


	
	// for (size_t i = 0; i < inp.height - 1; i++) {
	// 	for (size_t j = 0; j < inp.width; j++) {
	// 		if (date == inp.column_types->at(j))
	// 		{
	// 			if (inp.c->at((i * inp.width) + j))
	// 				cout << "date: " << *((t_date *)inp.c->at((i * inp.width) + j)) << " ";
	// 			else
	// 				cout << "date: nil";
	// 		}
	// 		else if (exchange_rate == inp.column_types->at(j))
	// 		{
	// 			if (inp.c->at((i * inp.width) + j))
	// 				cout << "exchange_rate: " << *((t_exchange_rate *)inp.c->at((i * inp.width) + j)) << " ";
	// 			else
	// 				cout << "exchange_rate: nil";
	// 		}
	// 		else if (unknown_type == inp.column_types->at(j))
	// 		{
	// 			if (inp.c->at((i * inp.width) + j))
	// 				cout << "unknown_type: " << inp.c->at((i * inp.width) + j) << " ";
	// 			else
	// 				cout << "unknown_type: nil";
	// 		}
	// 	}
	// 	cout << endl;
	// }
	
	
	// string		tofind("2016-07-16");

	// t_row		a_row = select_y(inp, 0, &tofind);
	// t_column	a_column = a_row[1];
	// cout << *(t_exchange_rate *)(select_y(inp, 0, &tofind)[1]) << endl;
	// cout << *(t_exchange_rate *)a_row[1] << endl;
	// cout << *(t_exchange_rate *)a_column << endl;
	
	
	// for (size_t i = 0; i < table.height - 1; i++) {
	// 	for (size_t j = 0; j < table.width; j++) {
	// 		if (date == table.column_types->at(j))
	// 			cout << "date: " << *((t_date *)table.c->at((i * table.width) + j)) << " ";
	// 		else if (exchange_rate == table.column_types->at(j))
	// 			cout << "exchange_rate: " << *((t_exchange_rate *)table.c->at((i * table.width) + j)) << " ";
	// 		else if (unknown_type == table.column_types->at(j))
	// 			cout << "unknown_type: " << table.c->at((i * table.width) + j) << " ";
	// 	}
	// 	cout << endl;
	// }
	
	
	// string		tofind("2016-07-16");

	// t_row		a_row = select_y(table, 0, &tofind);
	// t_column	a_column = a_row[1];
	// cout << *(t_exchange_rate *)(select_y(table, 0, &tofind)[1]) << endl;
	// cout << *(t_exchange_rate *)a_row[1] << endl;
	// cout << *(t_exchange_rate *)a_column << endl;

	

	// for (size_t i = 0; i < count; i++)
	// {
	// 	/* code */
	// }
	
	// std::find(table.begin(), table.end(), )
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
