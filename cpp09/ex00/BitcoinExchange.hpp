#ifndef BITCOIN_EXCHANGE_HPP_
#define BITCOIN_EXCHANGE_HPP_

#include <cstdlib>
#include <iostream>

#include "Database.hpp"

class BitcoinExchange {
 private:
  Database db_;

  bool check_value_(const std::string&);
  void process_valid_input_(const std::string&, double);

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

 public:
  BitcoinExchange(const Database&);
  ~BitcoinExchange();

  void process_line(const std::string&, bool);
};

#endif  // BITCOIN_EXCHANGE_HPP_
