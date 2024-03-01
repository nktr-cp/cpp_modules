#ifndef DATA_H_
#define DATA_H_

#include <cassert>
#include <string>

struct Data {
	std::string name;
	std::string coalition;
	unsigned int point;

	Data(std::string name, std::string coalition, unsigned int point)
	: name(name),
		coalition(coalition),
		point(point)
	{}
};

#endif // DATA_H_