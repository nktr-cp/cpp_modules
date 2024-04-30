#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <set>
#include <sstream>

class Span {
	private:
		Span();
		std::multiset<int> numbers_;
		unsigned int capacity_;
	public:
		Span(unsigned int);
		Span& operator=(const Span&);
		Span(const Span&);
		~Span();

		void addNumber(const int);
		template<typename InputIt>
		void addNumber(InputIt begin, InputIt end) {
			// maybe this is not necessary
			if (this->getSize() + std::distance(begin, end) > this->getCapacity()) {
				std::stringstream ss;
				ss << this->getCapacity();
				std::string err_msg = "Cannot store more than " + ss.str() + " integers!";
				throw std::runtime_error(err_msg);
			}

			for (InputIt it=begin; it!=end; ++it) {
				addNumber(*it);
			}
		}
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		size_t getSize() const;
		unsigned int getCapacity() const;
};

#endif // SPAN_HPP_
