#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {(void)other;}

Serializer& Serializer::operator=(const Serializer& other) {(void)other; return *this;}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	// uncomment this line, you will realize why it is required to use reinterpret_cast instead of static_cast
	// return static_cast<uintptr_t>(ptr);
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
