#if !defined(BITCOIN_EXCHANGE_HPP)
# define BITCOIN_EXCHANGE_HPP

# include "common.hpp"

# include <ctime>
# include <fstream>
# include <typeinfo>
# include <vector>
# include <algorithm>
# include <sstream>
# include <stdexcept>
# include <string>
# include <iostream>
# include <iterator>
# include <ostream>
# include <iomanip>

// using std::map;

#define DISCRIMINATOR_1				','
#define DISCRIMINATOR_2				'|'

#define DEFAULT_CSV_FILE			"./data.csv"

#define S_E_CORRUPTED_DB			"corrupted db"
#define S_E_SUCCES					"error of succes"
#define S_E_INSUFFICIENT_ARGUMENTS	"least 2 arg"
#define S_E_CANNOT_OPEN_FILE		"cannot open file"


typedef enum e_column {
	date = 0, // string
	value, // float
	exchange_rate, // float
	unknown_type
}		t_column_idx;

typedef string				t_date;
typedef float				t_exchange_rate;
typedef float				t_value;

// # define (type, id) (type*)id
// # define EXP(type, column, ) type* 
// 1typedef string

// typedef float t_price;

// typedef void**	t_row;
// typedef void*	t_column;

// typedef struct	s_csv {
// 	std::vector<void*>*			c; // possible w/o vector, with new void*[n]
// 	std::vector<t_column_idx>*	column_types;
// 	size_t						width;
// 	size_t						height;
// }				t_csv;



class BitcoinExchange {
	public:
		BitcoinExchange(string const& csv_file = string(DEFAULT_CSV_FILE));

		typedef float			t_price;
		void					calculate(string inp_file);
		std::vector<string>		csv_to_vec(string const& csv_file, char del);
		void					list(std::vector<string>& vec);
		std::vector<string>		db;
	private:
		std::vector<string> 	split(string& line, char sep);
		bool					vali_date_val(string& date_string, string& amount);
};

#endif // BITCOIN_EXCHANGE_HPP
