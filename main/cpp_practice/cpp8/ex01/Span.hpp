#if !defined(SPAN_HPP)
# define SPAN_HPP

# include <vector>
# include "common.hpp"

class Span {
	private:
		std::vector<int>	_v;
		std::vector<int>::iterator	_iter;
	public:
		Span();
		~Span();
		Span(Span& copy);
		Span& operator=(Span& rvalue);
		
		Span(unsigned int size);

		int shortestSpan();
		int longestSpan();
		unsigned int addNumber(int num);
};

#endif // SPAN_HPP


// -3 -4 -> -7

// -3 4 -> 1

