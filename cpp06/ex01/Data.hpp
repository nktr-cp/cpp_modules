#ifndef DATA_HPP_
#define DATA_HPP_

#include <string>

struct Data {
	std::string name;
	std::string coalition;
	unsigned int point;

	Data(std::string name, std::string coalition, unsigned int point);
	~Data();

	private:
		Data();
		Data(const Data&);
		Data operator=(const Data&);
};

#endif // DATA_HPP_
