#if !defined(BITCOIN_EXCHANGE_HPP)
# define BITCOIN_EXCHANGE_HPP

# include "common.hpp"
# include <map>

using std::map;

typedef int t_exchange;

class BitcoinExchange {
	t_exchange	bitcoin_value;

	map<string,t_exchange>* value_by_date;
};

#endif // BITCOIN_EXCHANGE_HPP
