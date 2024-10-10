#include "Span.hpp"

int f1 () {
	static int i = 0;
	return i+=33;
}

int main( void )
{
	Span sp;
	sp = Span(50);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.fill(f1);
	sp.fill(f1);
	sp.list();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	// for (std::vector<int>::iterator i = sp.begin(); i != sp.end() ; i++)
	// {
	// 	cout << *i << " ";
	// }
	
	return 0;
}
