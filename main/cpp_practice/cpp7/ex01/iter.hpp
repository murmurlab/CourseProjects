#include "common.hpp"

template <typename T>
void	iter(
		T* array,
		size_t length,
		void (&call_back)(size_t index, T* curr)
) {
	for (size_t i = 0; i < length; i++) call_back(i, array + i);
}
