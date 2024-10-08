#include <algorithm>
#include "Span.hpp"

using std::max;
using std::min;
using std::max_element;
using std::vector;
using std::min_element;

Span::Span()
{
}

Span::~Span() {
}

Span::Span(Span& copy) {
}

Span& Span::operator=(Span& rvalue) {
	// TODO: insert return statement here
}

Span::Span(unsigned int size) {
	_v = vector<int>(size);
	_iter = _v.begin();
}

int Span::shortestSpan() {
	int diff;
	int shortest;

	if (_v.size() < 2)
		throw (exception());
	shortest = max(_v[0], _v[1]) - min(_v[0], _v[1]);
	for (vector<int>::iterator it = _v.begin(); it != _v.end(); it++) {
		for (vector<int>::iterator jt = (it + 1); jt != _v.end(); jt++)
		{
			diff = max(*it, *jt) - min(*it, *jt);
			if (shortest > diff)
				shortest = diff;
		}
	}
	return shortest;
}

int Span::longestSpan() {
	if (_v.size() < 2)
		throw (exception());
	vector<int>::iterator
		a = max_element(_v.begin(), _v.end())
		,b = min_element(_v.begin(), _v.end());
	return (max(*a, *b) - min(*a, *b));
}

unsigned int Span::addNumber(int num) {
	// if ()
	return 0;
}
