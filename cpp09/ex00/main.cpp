#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

signed main(signed ac, char** av) {
  if (ac != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

  std::ifstream input(av[1]);
  if (!input.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

  try {
    Database db("data.csv");
    BitcoinExchange btc(db);

    std::string line;
    std::getline(input, line);
    btc.process_line(line, true);
    while (std::getline(input, line)) {
      btc.process_line(line, false);
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  input.close();
}
