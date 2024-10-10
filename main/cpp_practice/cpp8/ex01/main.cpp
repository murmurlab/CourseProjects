#include "Span.hpp"

int f1 () {
	static int i = 0;
	return i+=33;
}

int main( void )
{
	{
		cout << "==============Main test==============" << endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		cout << "=====================================" << endl << endl;
	}
	try
	{
		cout << "==============exceeded limit test==============" << endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "=====================================" << endl << endl;
	try
	{
		cout << "==============shortestSpan==============" << endl;
		Span sp(5);
		sp.addNumber(-11);
		// sp.addNumber(6);
		// sp.addNumber(7);
		cout << sp.shortestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "=====================================" << endl << endl;
	try
	{
		cout << "==============longestSpan==============" << endl;
		Span sp(5);
		sp.addNumber(-11);
		// sp.addNumber(6);
		// sp.addNumber(7);
		cout << sp.longestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "=====================================" << endl << endl;
	try
	{
		cout << "==============addNumber==============" << endl;
		// Span sp(0);
		// sp.addNumber(1);
		// Span sp2(1);
		// sp2.addNumber(1);
		// sp2.addNumber(1);
		Span sp3(2);
		sp3.addNumber(-1);
		sp3.addNumber(-1);
		sp3.addNumber(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "=====================================" << endl << endl;
	try
	{
		cout << "================fill================" << endl;
		Span sp(50);
		sp.fill(f1);
		// sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << "=====================================" << endl << endl;
	return 0;
}
