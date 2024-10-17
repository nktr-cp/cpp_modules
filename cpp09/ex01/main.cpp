#include "RPN.hpp"

signed main(signed ac, char** av) {
  if (ac != 2) {
    std::cerr << "Usage: " << av[0] << " <expression>" << std::endl;
    return 1;
  }

  try {
    RPN::process_expression(av[1]);
  } catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
