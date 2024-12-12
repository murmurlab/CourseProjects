#include "iter.hpp"

void my_cb(size_t index, string* curr) {
	cout << index << ": " << *curr << endl;
}

template<typename T>
void aa(size_t index, T* curr) {
	cout << index << ": " << *curr << endl;
}

int main( void ) {
	int intR[5] = { 0, 1, 2, 3, 4 };
	iter(intR, ft_size2(intR), aa); cout << endl;

	float floatR[7] = { 0.0f, 1.1f, 2.2f, 3.3f, 4.4f };
	iter(floatR, ft_size2(floatR), aa); cout << endl;

	double doubleR[] = { 0.00, 1.11, 2.22, 3.33, 4.44 };
	iter(doubleR, ft_size2(doubleR), aa); cout << endl;

	bool boolR[2] = { false, true };
	iter(boolR, ft_size2(boolR), aa); cout << endl;

	string stringR[5] = { "phrase 1", "phrase 2", "templates", "are", "fun" };
	iter(stringR, 5, aa); cout << endl;
	iter(stringR, 2, aa); cout << endl;
	iter(stringR, 0, aa); cout << endl;
	iter(stringR, ft_size2(stringR), my_cb); cout << endl;

	return 0;
}
