#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include "Data.h"
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

#endif // SERIALIZER_H_