#ifndef ARRAY_HPP_
#define ARRAY_HPP_

template<class T>
class Array {
	private:
		T* data_;
		unsigned int size_;

		void rebuild_(const unsigned int);
	public:
		Array();
		Array(const unsigned int);
		Array& operator=(const Array&);
		Array(const Array&);
		~Array();

		T& operator[](const unsigned int);
		const T& operator[](const unsigned int) const;
		unsigned int size() const;
};

#include "Array.tpp"

#endif // ARRAY_HPP_
