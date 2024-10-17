#ifndef BITCOIN_EXCHANGE_HPP_
#define BITCOIN_EXCHANGE_HPP_

#include <climits>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

/* Database */
class Database {
 private:
  std::map<std::string, double> table_;

 public:
  Database();
  Database(const std::string&);
  Database& operator=(const Database&);
  Database(const Database&);
  ~Database();

  std::map<std::string, double>::const_iterator getPrice(
      const std::string&) const;
  std::map<std::string, double>::const_iterator begin() const;
  std::map<std::string, double>::const_iterator end() const;

  static bool checkDate(const std::string& date);
};

/* BitcoinExchange */
class BitcoinExchange {
 private:
  Database db_;

  bool checkValue(const std::string&);
  void processValidInput(const std::string&, double);

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

 public:
  BitcoinExchange(const Database&);
  ~BitcoinExchange();

  void process_line(const std::string&, bool);
};

#endif  // BITCOIN_EXCHANGE_HPP_
