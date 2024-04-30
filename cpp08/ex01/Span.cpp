#include "Span.hpp"

Span::Span()
: capacity_(0)
{}

Span::Span(unsigned int N)
: capacity_(N)
{}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this == &other) {
		return *this;
	}

	numbers_ = other.numbers_;
	return *this;
}

Span::~Span() {}

void Span::addNumber(const int number) {
	if (this->getSize() >= this->getCapacity()) {
		std::stringstream ss;
		ss << this->getCapacity();
		std::string err_msg = "Cannot store more than " + ss.str() + " integars!";
		throw std::runtime_error(err_msg);
	}
	numbers_.insert(number);
}

unsigned int Span::shortestSpan() const {
	if (numbers_.size() <= 1) {
		throw std::runtime_error("Number of elements are not big enough!");
	}

	long minspan = LONG_MAX;
	std::multiset<int>::iterator it = numbers_.begin(); 
	std::multiset<int>::iterator fin_it = numbers_.end();
	--fin_it;	
	while (it != fin_it) {
		long value1 = *it++;
		long value2 = *it;
		minspan = std::min(minspan, value2-value1);
	}

	return static_cast<unsigned int>(minspan);
}

unsigned int Span::longestSpan() const {
	if (numbers_.size() <= 1) {
		throw std::runtime_error("Number of elements are not big enough!");
	}

	std::multiset<int>::iterator min_it = this->numbers_.begin();
	std::multiset<int>::iterator max_it = this->numbers_.end();
	--max_it;

	long min_value = *min_it;
	long max_value = *max_it;

	return static_cast<unsigned int>(max_value - min_value);
}

size_t Span::getSize() const {
	return this->numbers_.size();
}

unsigned int Span::getCapacity() const {
	return this->capacity_;
}
