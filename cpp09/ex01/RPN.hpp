#ifndef RPN_HPP_
#define RPN_HPP_

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
 private:
  RPN();
  RPN(const RPN&);
  RPN& operator=(const RPN&);
  ~RPN();

  static bool is_op_(const std::string);
  static int process_op_(const char, int, int);

 public:
  static void process_expression(const std::string&);
};

#endif  // RPN_HPP_
