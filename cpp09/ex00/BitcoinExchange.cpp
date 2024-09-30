#include "BitcoinExchange.hpp"

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

void BitcoinExchange::process_valid_input_(const std::string& date,
                                           double value) {
  std::map<std::string, double>::const_iterator it = db_.getPrice(date);
  if (it == db_.end()) {
    std::cout << "Error: no data for the given date or before" << std::endl;
    return;
  }

  std::cout << date << " => " << value << " = " << value * it->second
            << std::endl;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const Database& db) : db_(db) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : db_(other.db_) {
  *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  (void)other;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::process_line(const std::string& line,
                                   bool is_first = false) {
  std::istringstream iss(line);
  std::string date, valueStr;
  std::getline(iss, date, '|');
  std::getline(iss, valueStr, '|');

  // 余分な空白を取る
  if (!date.empty()) date.erase(date.find_last_not_of(" \t\r\n\v\f") + 1);
  if (!valueStr.empty())
    valueStr.erase(valueStr.find_first_of(" \t\r\n\v\f"), 1);

  if (is_first) {
    if (date.compare("date") || valueStr.compare("value")) {
      throw std::runtime_error("Invalid input");
    } else {
      return;
    }
  }
  if (!Database::check_date(date)) {
    std::cout << "Error: bad input => " << date << std::endl;
    return;
  }
  if (!check_value_(valueStr)) {
    std::cout << "Error: Invalid value input => " << valueStr << std::endl;
    return;
  }

  char* end;
  double value = std::strtod(valueStr.c_str(), &end);
  if (end == NULL || *end != '\0') {
    std::cout << "Invalid value input =>" << valueStr << std::endl;
    return;
  }

  if (value > INT_MAX) {
    std::cout << "Error: too large a number" << std::endl;
    return;
  }

  process_valid_input_(date, value);
}
