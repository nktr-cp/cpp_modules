#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& dummy) {(void)dummy;}

RPN& RPN::operator=(const RPN& dummy) {(void)dummy; return *this;}

RPN::~RPN() {}

bool RPN::is_op_(const char c) {
	return c == '+' || c == '-' || c == '/' || c == '*';
}

int RPN::process_op_(const char op, int a, int b) {
	switch(op) {
		case '+':
			return b + a;
		case '-':
			return b - a;
		case '*':
			return b * a;
		case '/':
			if (a == 0) {
				throw std::domain_error("Zero division");
			}
			return b / a;
		default:
			throw std::runtime_error("invalid operator");
			return 0;
	}
}

void RPN::process_expression(const std::string& expression) {
	std::stringstream ss(expression);
	std::string token;
	std::stack<int> st;

	while (ss >> token) {
		if (std::isdigit(token[0])) {
			if (token.size() > 1) {
				throw std::domain_error("input integer out of range");
			}
			st.push(token[0] - '0');
		} else if (is_op_(token[0])) {
			if (st.size() < 2) {
				throw std::runtime_error("not enough operands");
			}

			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			st.push(process_op_(token[0], a, b));
		} else {
			throw std::runtime_error("invalid input");
		}
	}

	if (st.size() != 1) {
		throw std::runtime_error("invalid expression");
	}
	std::cout << st.top() << std::endl;
}
