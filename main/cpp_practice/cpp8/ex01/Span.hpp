#if !defined(SPAN_HPP)
# define SPAN_HPP

# include "CustomizableException.hpp"
# include <algorithm>
# include <vector>

class Span {
	private:
		std::vector<int>			_v;
		std::vector<int>::iterator	_iter;
	public:
		Span();
		~Span();
		Span(Span const& copy);
		Span& operator=(Span const& rvalue);

		Span(unsigned int size);
		int shortestSpan();
		int longestSpan();
		void addNumber(int num);
		void fill(int (*fun)( void ));
		// void list();
};

#endif // SPAN_HPP
