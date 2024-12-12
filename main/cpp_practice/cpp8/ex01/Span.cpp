#include "Span.hpp"

using std::max;
using std::min;
using std::max_element;
using std::vector;
using std::min_element;

Span::Span() {
	cout<<"default ctor called"<<endl;
	_v = vector<int>(0);
	_iter = _v.begin();
}

Span::~Span() {
}

Span::Span(Span const& copy) {
	cout<<"copy constructor called"<<endl;
	operator=(copy);
}

Span& Span::operator=(Span const& rvalue) {
	// TODO: insert return statement here
	if (this == &rvalue)
		return *this;
	cout << "copy assignment operator called" << endl;
	_v = rvalue._v;
	_iter = _v.begin();
	std::advance(
		_iter ,
		std::distance <std::vector<int>::const_iterator> (
			rvalue._v.begin(), rvalue._iter
		)
	);
	return *this;
}

Span::Span(unsigned int size) {
	cout<<"ctor called"<<endl;
	_v = vector<int>(size);
	_iter = _v.begin();
}

// void Span::list() {
// 	for (size_t i = 0; i < _v.size(); i++)
// 	{
// 		cout << _v[i] << endl;
// 	}
// }

int Span::shortestSpan() {
	int diff;
	int shortest;

	if (std::distance(_v.begin(), _iter) < 2)
		throw (CustomizableException("Span must have least 2 element"));
	shortest = max(_v[0], _v[1]) - min(_v[0], _v[1]);
	for (vector<int>::iterator it = _v.begin(); it != _iter; it++) {
		for (vector<int>::iterator jt = (it + 1); jt != _iter; jt++)
		{
			diff = max(*it, *jt) - min(*it, *jt);
			if (shortest > diff)
				shortest = diff;
		}
	}
	return shortest;
}

int Span::longestSpan() {
	if (std::distance(_v.begin(), _iter) < 2)
		throw (CustomizableException("Span must have least 2 element"));
	vector<int>::iterator
		a = max_element(_v.begin(), _iter)
		,b = min_element(_v.begin(), _iter);
	return (max(*a, *b) - min(*a, *b));
}

void Span::addNumber(int num) {
	if (_iter == _v.end())
		throw (CustomizableException("Span is full"));
	*(_iter++) = num;
}

void Span::fill(int (*fun)( void )) {
	std::generate(_v.begin(), _v.end(), fun);
	_iter = _v.end();
}
