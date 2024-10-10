#include <algorithm>
#include "Span.hpp"

using std::max;
using std::min;
using std::max_element;
using std::vector;
using std::min_element;

Span::Span() {
	_v = vector<int>(0);
	_iter = _v.begin();
}

Span::~Span() {
}

Span::Span(Span const& copy) {
	operator=(copy);
}

Span& Span::operator=(Span const& rvalue) {
	// TODO: insert return statement here
	_v = rvalue._v;
	_iter = _v.begin();
	return *this;
}

Span::Span(unsigned int size) {
	_v = vector<int>(size);
	_iter = _v.begin();
}

void Span::list() {
	for (size_t i = 0; i < _v.size(); i++)
	{
		cout << _v[i] << endl;
	}
	
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

void Span::addNumber(int num) {
	if (_iter == _v.end())
		throw (exception());
	*(_iter++) = num;
}

void Span::fill(int (*fun)( void )) {
	std::generate(_v.begin(), _v.end(), fun);
	_iter = _v.end();
}
