template <typename T>
typename T::iterator easyfind(T in, int val) {
	return T::iterator(std::find(in.begin(), in.end(), val));
}
