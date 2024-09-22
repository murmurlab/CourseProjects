#include "Serializer.hpp"

int main( void )
{
	Data	tada = {
		.a = 11,
		.b = 21,
		.c = 33,
		.d = 42
	};
	Data	second;
	Data* const	an_unnamed_data = &tada;
	void* ptr;

	uintptr_t a = Serializer::serialize(an_unnamed_data);
	cout << "original address: " << an_unnamed_data << endl;
	cout << "serial value: " << a << endl;
	ptr = Serializer::deserialize(a);
	cout << "deserial from serial value: " << ptr << endl;
	cout << "original addr == deserial addr => "
		<< std::boolalpha << (an_unnamed_data == ptr) << endl;
	second = *an_unnamed_data;
	cout << std::memcmp(&tada, &second, sizeof(Data)) << endl;
	return 0;
}
