#include "Database.hpp"

Database::Database() {}

#include <iostream>
Database::Database(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Error: Invalid database file");
	}

	std::string line;
	bool is_first_line = true;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string data, priceStr;
		std::getline(iss, data, ',');
		std::getline(iss, priceStr);

		if (is_first_line) {
			if (data.compare("date") || priceStr.compare("exchange_rate")) {
				throw std::runtime_error("Error: invalid database");
			}
			is_first_line &= false;
		} else {
			char *end;
			double price = std::strtod(priceStr.c_str(), &end);
			if (end == NULL || *end != '\0') {
				throw std::runtime_error("Error: Invalid database");
			}

			table_[data] = price;
		}
	}
	file.close();
}

Database::Database(const Database& other)
: table_(other.table_)
{}

Database& Database::operator=(const Database& other) {
	if (this == &other) {
		return *this;
	}

	this->table_.clear();
	this->table_ = other.table_;
	return *this;
}

Database::~Database() {}

std::map<std::string, double>::const_iterator Database::getPrice(const std::string& data) const {
	std::map<std::string, double>::const_iterator it = table_.upper_bound(data);
	if (it == table_.begin()) {
		return table_.end();
	} else {
		return --it;
	}
}

std::map<std::string, double>::const_iterator Database::begin() const {
	return table_.begin();
}

std::map<std::string, double>::const_iterator Database::end() const {
	return table_.end();
}

