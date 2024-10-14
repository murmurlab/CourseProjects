#include "BitcoinExchange.hpp"

static string	trim(string const& str) {
	return str.substr(str.find_first_not_of(WS), str.find_last_not_of(WS)+1);	
}

std::vector<string> BitcoinExchange::split(string& line, char sep) {
	std::vector<string> ret;
	
	std::istringstream iss(line.c_str());
	size_t l = line.length();
	char* node = new char[l];
	string trimmed;
	for (bool stat; ((stat = iss.getline(node, l, sep)) || !(trimmed = trim(iss.str())).empty());) {
		// cout << "stat:" << stat << " eof:"<< iss.eof() << " s: \"" << line << "\" - " << node << endl<< endl;
		if (iss.eof() && !stat) break;
		if (!stat) {
			ret.push_back(trimmed);
			ret.push_back(string(""));
			break ;
		} else {
			// cout << "split: " << node << endl;
			string s(node);
			ret.push_back(trim(s));
		}
	}
	delete[] node;
	return (ret);
}

BitcoinExchange::BitcoinExchange(string const& csv_file) {
	db = csv_to_vec(csv_file, ',');
	// if ("date,exchange_rate" != line)
	// 	throw (runtime_error(S_E_CORRUPTED_DB));
	
	// std::istringstream iss(line.c_str());
	// size_t l = line.length(); 
	// char* node = new char[l];
	// for (; iss.getline(node, l, seperator);) {
	// 	string untrimmed(node);
	// 	string trimmed;
	// 	std::istringstream str(untrimmed);
	// 	str >> trimmed;
	// 	// cout << trimmed << endl;
	// 	t.column_types->push_back(
	// 		(trimmed == string("date")) ?			date :
	// 		(trimmed == string("value")) ?			value :
	// 		(trimmed == string("exchange_rate")) ?	exchange_rate :
	// 											unknown_type
	// 	);
	// 	cout << "\t" << trimmed << endl;
	// 	cout << "\t\t typedef " << trimmed << " " << t.column_types->back() << endl;
	// }
	// t.width = t.column_types->size();
	// t.c = new std::vector<void*>(t.width * t.height);
	// // table[(399 * coloumns) + 1] = NULL;

	// for (size_t row(0); std::getline(readable, line); row++) {
	// 	cout << line << endl;
	// 	std::istringstream iss_tmp(line.c_str());
	// 	int col = t.column_types->front();
	// 	size_t le = line.length();
	// 	char* node = new char[le];
		
	// 	bool cont = true;
	// 	for (; cont; col++) {
	// 		cont = iss_tmp.getline(node, le, seperator);

	// 		if (!cont)
	// 			t.c->at((row * t.width) + col) = NULL;
	// 		else {
	// 			// (coloumn_types[col] == date) ?			("NULL") :
	// 			// (coloumn_types[col] == exchange_rate) ?	(NULL) :
	// 			// 											(NULL)
	// 			string untrimmed(node);
	// 			string trimmed;
	// 			std::istringstream str(untrimmed);
	// 			str >> trimmed;
	// 			cout << "\t" << "<" << t.column_types->at(col) << ">" << trimmed << endl;
	// 			t.c->at((row * t.width) + col) = serialize(t.column_types->at(col) ,(char *)trimmed.c_str());
	// 		}
	// 		// if 
	// 		// table[(row * coloumns) + col] = NULL;
	// 	}
	// }
	// return t;
}

std::vector<string> BitcoinExchange::csv_to_vec(string const& csv_file, char del) {
	std::vector<string> ret;
	
	std::ifstream db_file(csv_file.c_str());
	if (!db_file) throw(runtime_error(S_E_CANNOT_OPEN_FILE));
	std::ostringstream content;
	content << db_file.rdbuf();
	string all(content.str());
	std::istringstream all_lines(all);

	string	head;

	std::getline(all_lines, head);
	std::vector<string> list = split(head, del);
	if (list.size() != 2) {
		throw (runtime_error(S_E_CORRUPTED_DB": 2 head err"));
	}
	if (del == '|') {
		if (list[0] != "date" || list[1] != "value")
			throw (runtime_error(S_E_CORRUPTED_DB": '|' head err"));			
	} else if (del == ',') {
		if (list[0] != "date" || list[1] != "exchange_rate")
			throw (runtime_error(S_E_CORRUPTED_DB": ',' head err"));
	}

	// cout << list[0] << " / " << list[1] << endl;

	for (string line; std::getline(all_lines, line);) {
		list = split(line, del);
		if (list.size() < 2) {
			ret.push_back(list[0]);
			ret.push_back(string(""));
			// throw (runtime_error(S_E_CORRUPTED_DB));
		} else {
			ret.insert(ret.end(), list.begin(), list.end());
		}
		// cout << list[0] << " / " << list[1] << endl;
		// cout << line << endl;
		// for (; line.getline();)
	}
	return ret;
}



static bool relative_versus(time_t relative_1, time_t relative_2, time_t base) {
	
}

bool BitcoinExchange::vali_date_val(string& date_string, string& amount) {
	// if ()
	return false;
}

void BitcoinExchange::calculate(string inp_file) {
	// list(db);
	std::vector<string> db_in = csv_to_vec(inp_file, '|');
	for (std::vector<string>::iterator it = db_in.begin(); it != db_in.end(); it+=2) {
		if (vali_date_val(*it, *(it + 1)))
			continue ;
		std::vector<string>::iterator closest = db.begin();
		for (std::vector<string>::iterator it2 = db.begin(); it2 != db.end(); it2+=2) {
			if (*it == *it2) {
				cout << *it2 << " " << *(it2 + 1) << endl;
				break ;
			}
			if (which_is_closest(closest, it2, it))
		}
		// cout << *it << " " << *(it + 1) << endl;
	}

	// list(db_in);
}

static void p(string& s) {
	cout << s << endl;
}

void BitcoinExchange::list(std::vector<string>& vec) {
	for (std::vector<string>::iterator it = vec.begin(); it != vec.end(); it+=2) {
		cout << *it << " " << *(it + 1) << endl;
	}
	// std::for_each(db.begin(), db.end(), p);
}
