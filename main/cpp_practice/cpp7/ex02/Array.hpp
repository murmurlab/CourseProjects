#if !defined(ARRAY_HPP)
# define ARRAY_HPP

# include "common.hpp"
# include "ArrayExceedIndexException.hpp"

template <typename T>
class Array {
	private:
		unsigned int _size;
		T* _data;
	public:
		Array();
		Array(unsigned int n);
		Array(Array& cpy);
		~Array ();
		unsigned int size() const;
		Array& operator=(Array& rval);
		T& operator[](unsigned int index);
};

# include "Array.tpp"

#endif // ARRAY_HPP
