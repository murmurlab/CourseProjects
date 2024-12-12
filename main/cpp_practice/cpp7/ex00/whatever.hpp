#if !defined(whatever_hpp)
# define whatever_hpp

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& max(T& a, T& b) {
	return (b >= a ? b : a);
}

template <typename T>
T& min(T& a, T& b) {
	return (a >= b ? b : a);
}

#endif // whatever_hpp
