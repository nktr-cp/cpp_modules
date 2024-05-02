#ifndef RPN_HPP_
#define RPN_HPP_

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <stack>

class RPN {
	private:
		RPN();
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		static bool is_op_(const char);
		static int process_op_(const char, int, int);
	public:
		static void process_expression(const std::string&);
};

#endif // RPN_HPP_
