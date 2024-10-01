#if !defined(ARRAY_TPP)
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array(): _size(0), _data(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _data(new T[n]) {}

template <typename T>
Array<T>::Array(Array& cpy): _data(NULL) {
	operator=(cpy);
}

template <typename T>
Array<T>::~Array () {
	delete[] _data;
}	

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if ((index >= _size) || (index < 0))
		throw(ArrayExceedIndexException("exceed index"));
	return _data[index];
}

template <typename T>
Array<T>& Array<T>::operator=(Array& rval) {
	Array::~Array();
	_size = rval.size();
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_data[i] = rval._data[i];
	return *this;
}

#endif // ARRAY_TPP
