#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(BitcoinExchange& other) {
	operator=(other);
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& rvalue) {
	this->db = rvalue.db;
	return *this;
}

static string	trim(string const& str) {
	if (str.empty())
		return ("");
	size_t first = str.find_first_not_of(WS);
	size_t last = str.find_last_not_of(WS);
	return str.substr(first, (last - first) + 1);
}

std::vector<string> BitcoinExchange::split(string& line, char sep, bool debug) {
	std::vector<string> ret;
	
	std::istringstream iss(line.c_str());
	string node;
	string trimmed;
	for (bool stat; ((stat = std::getline(iss, node, sep)) || !(trimmed = trim(iss.str())).empty());) {
		// cout << "stat:" << stat << " eof:"<< iss.eof() << " s: \"" << line << "\" - " << node << endl<< endl;
			// ret.push_back(string(""));
		if (iss.eof() && !stat) {
			if (ret.size() == 1)
				ret.push_back(string(""));
			break;
		}
		if (!stat) {
			ret.push_back(trimmed);
			ret.push_back(string(""));
			break ;
		} else {
			string tmp = trim(node);
			if (debug) { cout << "|" << tmp << "#" << (node) << "|" << endl;}
			ret.push_back(trim(node));
		}
	}
	return (ret);
}

BitcoinExchange::BitcoinExchange(string const& csv_file) {
	db = csv_to_vec(csv_file, ',');
}

std::vector<string> BitcoinExchange::csv_to_vec(string const& csv_file, char del) {
	
	std::ifstream db_file(csv_file.c_str());
	if (!db_file) throw(runtime_error(S_E_CANNOT_OPEN_FILE));
	std::ostringstream content;
	content << db_file.rdbuf();
	string all(content.str());
	std::istringstream all_lines(all);

	string	head;
	std::getline(all_lines, head);
	for (; trim(head).empty() ; std::getline(all_lines, head));
	
	std::vector<string> list = split(head, del, false);
	if (list.size() != 2) {
		throw (runtime_error(S_E_CORRUPTED_DB": 2 head err"));
	}
	if (del == '|') {
		// cout << list[1] << "********** " << endl;
		if (list[0] != "date" || list[1] != "value")
			throw (runtime_error(S_E_CORRUPTED_DB": '|' head err"));			
	} else if (del == ',') {
		// cout << list[1] << "********** " << endl;
		if (list[0] != "date" || list[1] != "exchange_rate")
			throw (runtime_error(S_E_CORRUPTED_DB": ',' head err"));
	}

	// cout << list[0] << " / " << list[1] << endl;

	std::vector<string> ret;
	
	// for (std::getline(all_lines, head); trim(head).empty(); std::getline(all_lines, head));
	for (string line; std::getline(all_lines, line);) {
		// for (; trim(head).empty() ; std::getline(all_lines, head));
		list.clear();
		list = split(line, del, false);
		if (list.size() < 2) {
			ret.push_back(list[0]);
			ret.push_back(string(""));
			throw (runtime_error(S_E_CORRUPTED_DB": 22"));
		} else {
			ret.insert(ret.end(), list.begin(), list.end());
		}
		// cout << list[0] << " / " << list[1] << endl;
		// cout << line << endl;
		// for (; line.getline();)
		if (del == ',' && vali_date_val(*(ret.end() - 2), *(ret.end() - 1), 1))
		{
			cout << *(ret.end() - 2) << " " << *(ret.end() - 1) << endl;
			throw (runtime_error(S_E_CORRUPTED_DB": ',' corrupted line"));
		}

	}

	return ret;
}

static bool get_date(const std::string& dateStr, std::time_t* date) {
	std::tm tm = {};
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-' ||
		!isdigit(dateStr[0]) ||
		!isdigit(dateStr[1]) ||
		!isdigit(dateStr[2]) ||
		!isdigit(dateStr[3]) ||
		!isdigit(dateStr[5]) ||
		!isdigit(dateStr[6]) ||
		!isdigit(dateStr[8]) ||
		!isdigit(dateStr[9]))
		return true;
    
    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());
    
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return true;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return true;
    }
	else if (month == 2) {
        if ((year % 4 == 0) && !((year % 400 != 0) && (year % 100 == 0))) {
            if (day > 29)
                return true;
        } else if (day > 28) {
			return true;
        }
    }
	if (date == NULL)
		return false ;
	tm.tm_year = year;
	tm.tm_mon = month;
	tm.tm_mday = day;
	*date = std::mktime(&tm);
    return false;
}

static bool relativeTernaryComparison(string& factor_1, string& factor_2, string& criterion) {
	std::time_t f1, f2, c1;
	
	get_date(factor_1, &f1);
	get_date(factor_2, &f2);
	if (get_date(criterion, &c1))
		return false ;
	if ((std::abs(std::difftime(f1, c1)) > std::abs(std::difftime(f2, c1))) && (f2 < c1))
		return true;
	return false;
}

bool BitcoinExchange::vali_date_val(string& date_string, string& amount, bool mod) {
	if (get_date(date_string, NULL)) {
		cout << "Error: bad input => \"" << date_string << " | " << amount << "\"" << endl;
		return true;
	}
	char *er = NULL;
	strtod(amount.c_str(), &er);
	if (*er) {
		cout << "Error: not a valid number." << endl;
		return true;
	}
	float a = atof(amount.c_str());
	if (amount.find("-") != std::string::npos) {
		cout << "Error: not a positive number." << endl;
		return true;
	}
	if ((amount.size() > 4 || a > 1000) && !mod) {
		cout << "Error: too large a number.: " << endl;
		return true;
	}
	return false;
}

void BitcoinExchange::calculate(string inp_file) {
	// list(db);
	std::vector<string> db_in = csv_to_vec(inp_file, '|');
	for (std::vector<string>::iterator it = db_in.begin(); it != db_in.end(); it+=2) {
		if (vali_date_val(*it, *(it + 1))) {
			continue ;
		}
		std::vector<string>::iterator closest = db.begin();
		for (std::vector<string>::iterator it2 = db.begin(); it2 != db.end(); it2+=2) {
			if (*it == *it2) {
				closest = it2;
				break ;
			}
			else if (relativeTernaryComparison(*closest, *it2, *it))
				closest = it2;
		}
		cout << *(it) << " => " << *(closest) << " | " << "(" << *(it + 1) << " * " << *(closest + 1) << ") = " << (t_price)(std::atof((it + 1)->c_str()) * std::atof((closest + 1)->c_str())) << endl;
		// cout << *it << " " << *(it + 1) << endl;
	}

	// list(db_in);
}

// static void p(string& s) {
// 	cout << s << endl;
// }

void BitcoinExchange::list(std::vector<string>& vec) {
	for (std::vector<string>::iterator it = vec.begin(); it != vec.end(); it+=2) {
		cout << *it << " " << *(it + 1) << endl;
	}
	// std::for_each(db.begin(), db.end(), p);
}
