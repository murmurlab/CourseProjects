#include "common.hpp"
#include "NotFoundElement.hpp"

template <typename T>
typename T::iterator easyfind(T &in, int val) {
	typename T::iterator found(std::find(in.begin(), in.end(), val));
	if (found == in.end())
		throw (NotFoundElement("container element not found"));
	return found;
}
