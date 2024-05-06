#include "Database.hpp"

Database::Database() {}

bool Database::check_date(const std::string& date) {
	int year, month, day;
	std::istringstream iss(date);
	char delim1, delim2;

	iss >> year >> delim1 >> month >> delim2 >> day;

	if (iss.fail() || iss.get() != EOF || delim1 != '-' || delim2 != '-') {
		return false;
	}

	// yearのバリデーションは適当
	if (year > 2025 || year < 2000) return false;
	// month-day
	if (day < 1 || month < 1 || month > 12) return false;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12) && day > 31) return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
	if (month == 2 && day > 29) return false; 

	return true;
}

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

		if (iss.fail() || iss.get() != EOF) {
			throw std::runtime_error("Error: invalid database");
		}

		if (is_first_line) {
			if (data.compare("date") || priceStr.compare("exchange_rate")) {
				throw std::runtime_error("Error: invalid database");
			}
			is_first_line &= false;
		} else {
			if (!Database::check_date(data)) {
				throw std::runtime_error("Error: invalid database");
			}
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

