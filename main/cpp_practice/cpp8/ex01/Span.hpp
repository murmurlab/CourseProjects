#if !defined(SPAN_HPP)
# define SPAN_HPP

# include <vector>
# include "common.hpp"

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
		void list();
		void fill(int (*fun)( void ));
};

#endif // SPAN_HPP
