#if !defined(BITCOIN_EXCHANGE_HPP)
# define BITCOIN_EXCHANGE_HPP

# include "common.hpp"

# include <ctime>
# include <cstdlib>
# include <fstream>
# include <vector>
# include <sstream>


#define DISCRIMINATOR_1				','
#define DISCRIMINATOR_2				'|'

#define DEFAULT_CSV_FILE			"./data.csv"

#define S_E_CORRUPTED_DB			"corrupted db"
#define S_E_SUCCES					"error of succes"
#define S_E_INSUFFICIENT_ARGUMENTS	"least 2 arg"
#define S_E_CANNOT_OPEN_FILE		"cannot open file"



class BitcoinExchange {
	public:
		BitcoinExchange(string const& csv_file = string(DEFAULT_CSV_FILE));
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange& other);
		BitcoinExchange&	operator=(BitcoinExchange& rvalue);
		
		typedef float			t_price;
		void					calculate(string inp_file);
		std::vector<string>		csv_to_vec(string const& csv_file, char del);
		void					list(std::vector<string>& vec);
		std::vector<string>		db;
	private:
		std::vector<string> 	split(string& line, char sep, bool deb);
		bool					vali_date_val(string& date_string, string& amount,bool mod=0);
};

#endif // BITCOIN_EXCHANGE_HPP
