#include "BitcoinExchange.hpp"

/* Database */
Database::Database() {}

bool Database::checkDate(const std::string& date) {
  if (date.length() != 10) {
    return false;
  }

  std::string year_str = date.substr(0, 4);
  std::string month_str = date.substr(5, 2);
  std::string day_str = date.substr(8, 2);

  if (date[4] != '-' || date[7] != '-') {
    return false;
  }

  int year;
  std::istringstream year_iss(year_str);
  year_iss >> year;
  if (year_iss.fail() || year_iss.get() != EOF || year > 2025 || year < 2009) {
    return false;
  }

  int month;
  std::istringstream month_iss(month_str);
  month_iss >> month;
  if (month_iss.fail() || month_iss.get() != EOF || month < 1 || month > 12) {
    return false;
  }

  int day;
  std::istringstream day_iss(day_str);
  day_iss >> day;
  if (day_iss.fail() || day_iss.get() != EOF || day < 1) {
    return false;
  }

  if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
       month == 10 || month == 12) &&
      day > 31) {
    return false;
  }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
    return false;
  }
  if (month == 2) {
    if (year % 4 == 0 && day > 29) return false;
    if (year % 4 != 0 && day > 28) return false;
  }

  return true;
}

Database::Database(const std::string& filename) {
  std::ifstream file(filename.c_str());
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
      if (!Database::checkDate(data)) {
        throw std::runtime_error("Error: invalid database");
      }
      char* end;
      double price = std::strtod(priceStr.c_str(), &end);
      if (end == NULL || *end != '\0') {
        throw std::runtime_error("Error: Invalid database");
      }

      table_[data] = price;
    }
  }
  file.close();
}

Database::Database(const Database& other) : table_(other.table_) {}

Database& Database::operator=(const Database& other) {
  if (this == &other) {
    return *this;
  }

  this->table_.clear();
  this->table_ = other.table_;
  return *this;
}

Database::~Database() {}

std::map<std::string, double>::const_iterator Database::getPrice(
    const std::string& data) const {
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

/* Bitcoin Exchange */
bool BitcoinExchange::checkValue(const std::string& valueStr) {
  double value;
  std::istringstream iss(valueStr);
  iss >> value;

  if (iss.fail() || iss.get() != EOF) {
    std::cerr << "Error: invalid value input => " << valueStr << std::endl;
    return false;
  }

  if (value < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  } else if (value > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return false;
  }

  return true;
}

void BitcoinExchange::processValidInput(const std::string& date, double value) {
  std::map<std::string, double>::const_iterator it = db_.getPrice(date);
  if (it == db_.end()) {
    std::cerr << "Error: no data for the given date or before" << std::endl;
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
  if (!Database::checkDate(date)) {
    std::cerr << "Error: bad input => " << date << std::endl;
    return;
  }
  if (!checkValue(valueStr)) {
    return;
  }

  char* end;
  double value = std::strtod(valueStr.c_str(), &end);
  if (end == NULL || *end != '\0') {
    std::cerr << "Invalid value input =>" << valueStr << std::endl;
    return;
  }

  if (value > INT_MAX) {
    std::cerr << "Error: too large a number" << std::endl;
    return;
  }

  processValidInput(date, value);
}
