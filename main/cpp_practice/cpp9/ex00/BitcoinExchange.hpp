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

typedef float t_price;

typedef void**	t_row;
typedef void*	t_column;

typedef struct	s_csv {
	std::vector<void*>*			c; // possible w/o vector, with new void*[n]
	std::vector<t_column_idx>*	column_types;
	size_t						width;
	size_t						height;
}				t_csv;

// class BitcoinExchange {
// 	public:
// 		BitcoinExchange(string csv_file = string(DEFAULT_CSV_FILE), );

// 		typedef float t_price;
// 		bitcoin_value(t_price );
// 	private:
// 		t_price	bitcoin_value;

// 		map<string,t_price>* value_by_date;
// };

#endif // BITCOIN_EXCHANGE_HPP
