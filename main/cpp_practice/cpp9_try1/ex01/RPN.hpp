#if !defined(RPN_HPP)
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <stack>
# include "common.hpp"

class RPN {
	private:
		std::stack<int>		nums;
		std::stack<char>	ops;
		std::string			raw_exp;

		int		is_opt(char opt);
		void	operate();
	public:
		RPN(std::string in);
		RPN(RPN const& src);
		RPN& operator=(RPN const& assign);
		~RPN();
};

#endif // RPN_HPP


