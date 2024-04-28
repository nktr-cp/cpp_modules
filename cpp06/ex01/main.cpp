#include <iostream>
#include "Serializer.hpp"

signed main() {
	Data d("knishiok", "FireRed", 5148);

	uintptr_t serialized_ptr = Serializer::serialize(&d);

	Data* deserialzed_ptr = Serializer::deserialize(serialized_ptr);

	assert(&d == deserialzed_ptr);
	std::cout << d.name << " " << deserialzed_ptr->name << std::endl;
	std::cout << d.coalition << " " << deserialzed_ptr->coalition << std::endl;
	std::cout << d.point << " " << deserialzed_ptr->point << std::endl;
}
