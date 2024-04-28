#include "Data.hpp"

Data::Data(std::string name, std::string coalition, unsigned int point)
: name(name),
	coalition(coalition),
	point(point)
{}

Data::Data() {}

Data::Data(const Data& other) {(void)other;}

Data Data::operator=(const Data& other) {(void)other; return *this;}

Data::~Data() {}
