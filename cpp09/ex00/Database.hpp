#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

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

  static bool check_date(const std::string& date);
};

#endif  // DATABASE_HPP