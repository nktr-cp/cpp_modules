#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>

template<class T, class F>
void iter(T *array, size_t length, F func) {
	for (size_t i=0; i<length; i++) {
		func(array[i]);
	}
}

#endif // ITER_HPP_
