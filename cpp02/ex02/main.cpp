#include <iostream>
#include "Fixed.h"

signed main( void ) {
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c (3.45f);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "++++++++++++++++++++++++" << std::endl;
	// increament/decrement
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "++++++++++++++++++++++++" << std::endl;
	// comparison operators
	std::cout << ((b > c) ? b : c) << std::endl;
	std::cout << ((b >= c) ? b : c) << std::endl;
	std::cout << ((b < c) ? b : c) << std::endl;
	std::cout << ((b <= c) ? b : c) << std::endl;
	std::cout << ((b != c) ? b : c) << std::endl;
	std::cout << ((b == c) ? b : c) << std::endl;
	std::cout << "++++++++++++++++++++++++" << std::endl;
	// arithmetic operators
	std::cout << b+c << std::endl;
	std::cout << b-c << std::endl;
	std::cout << b*c << std::endl;
	std::cout << b/c << std::endl;
	// min, max
	std::cout << "++++++++++++++++++++++++" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( b, c ) << std::endl;
	std::cout << "++++++++++++++++++++++++" << std::endl;
	return 0;
}