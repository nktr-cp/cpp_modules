#include "BitcoinExchange.hpp"

bool BitcoinExchange::check_date_(const std::string& date) {
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

bool BitcoinExchange::check_value_(const std::string& valueStr) {
	double value;
	std::istringstream iss(valueStr);
	iss >> value;

	if (iss.fail() || iss.get() != EOF) {
		return false;
	}

	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	} else if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::process_valid_input_(const std::string& date, double value) {
	std::map<std::string, double>::const_iterator it = db_.getPrice(date);
	if (it == db_.end()) {
		std::cout << "Error: no data for the given date or before" << std::endl;
		return;
	}

	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const Database& db)
: db_(db)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
: db_(other.db_)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::process_line(const std::string &line, bool is_first = false) {
	std::istringstream iss(line);
	std::string date, valueStr;
	std::getline(iss, date, '|');
	std::getline(iss, valueStr, '|');

	// 余分な空白を取る
	if (!date.empty()) date.erase(date.find_last_not_of(" \t\r\n\v\f") + 1);
	if (!valueStr.empty()) valueStr.erase(valueStr.find_first_of(" \t\r\n\v\f"), 1);

	if (is_first) {
		if (date.compare("date") || valueStr.compare("value")) {
			throw std::runtime_error("Invalid input");
		} else {
			return;
		}
	}
	if (!check_date_(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}
	if (!check_value_(valueStr)) {
		return;
	}

	char *end;
	double value = std::strtod(valueStr.c_str(), &end);
	if (end == NULL || *end != '\0') {
		std::cout << "Invalid value input =>" << valueStr << std::endl;
		return;
	}

	if (value > std::numeric_limits<int>::max()) {
		std::cout << "Error: too large a number" << std::endl;
		return;
	}

	process_valid_input_(date, value);
}
