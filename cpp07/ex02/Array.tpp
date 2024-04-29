template<class T>
void Array<T>::rebuild_(const unsigned int size) {
	T* new_data = new T[size]();
	delete[] data_;
	data_ = new_data;
	size_ = size;
}

template<class T>
Array<T>::Array()
: data_(NULL),
	size_(0)
{}

template<class T>
Array<T>::Array(const unsigned int n)
: data_(new T[n]()),
	size_(n)
{}

template<class T>
Array<T>::Array(const Array<T>& other)
: data_(NULL),
	size_(0)
{
	*this = other;
}

template<class T>
Array<T> Array<T>::operator=(const Array<T>& other) {
	if (this == &other) {
		return *this;
	}

	this->rebuild_(other.size());
	for (unsigned int i=0; i<other.size(); i++) {
		data_[i] = other[i];
	}
	return *this;
}

template<class T>
Array<T>::~Array() {
	delete[] data_;
}

template<class T>
T& Array<T>::operator[](const unsigned int n) const {
	if (n >= this->size()) {
		throw std::out_of_range("Array: index out of range");
	}
	return data_[n];
}

// template<class T>
// const T& Array<T>::operator[](const unsigned int n) const {
// 	if (n >= this->size()) {
// 		throw std::out_of_range("Array: index out of range");
// 	}
// 	return data_[n];
// }

template<class T>
unsigned int Array<T>::size() const {
	return this->size_;
}
