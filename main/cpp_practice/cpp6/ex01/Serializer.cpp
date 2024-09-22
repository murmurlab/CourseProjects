#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr) {
	return uintptr_t(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return (Data *)(raw);
}
