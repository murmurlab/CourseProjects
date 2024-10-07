#if !defined(SPAN_HPP)
# define SPAN_HPP

# include <vector>
# include "common.hpp"

class Span {
	private:
		std::vector<int>	_v;
	public:
		Span();
		~Span();
		Span(Span& copy);
		Span& operator=(Span& rvalue);
		
		Span(unsigned int size);
		unsigned int addNumber(int num);
};

#endif // SPAN_HPP
