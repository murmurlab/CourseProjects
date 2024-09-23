#include "Serializer.hpp"

Serializer::Serializer(Serializer& cpy) {(void)cpy;}
Serializer::Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr) {
	return uintptr_t(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return (Data *)(raw);
}
