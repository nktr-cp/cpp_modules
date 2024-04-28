#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

#include "Data.hpp"
#include <cstdint>

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		~Serializer();

	public:
		static uintptr_t serialize(Data*);
		static Data* deserialize(uintptr_t);
};

#endif // SERIALIZER_HPP_
