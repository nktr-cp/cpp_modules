#ifndef FIXED_H_
#define FIXED_H_

#include <string>
#include <iostream>

class Fixed {
	private:
		int	value_;
		static const int fractionalBits = 8;
	public:
		Fixed();

		Fixed(const int);
		Fixed(const float);

		Fixed(const Fixed&);

		~Fixed();

		Fixed& operator=(const Fixed&);
		bool operator>(const Fixed&) const;
		bool operator<(const Fixed&) const;
		bool operator>=(const Fixed&) const;
		bool operator<=(const Fixed&) const;
		bool operator==(const Fixed&) const;
		bool operator!=(const Fixed&) const;

		Fixed operator+(const Fixed&);
		Fixed operator-(const Fixed&);
		Fixed operator*(const Fixed&);
		Fixed operator/(const Fixed&);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

		int getRawBits(void) const;
		void setRawBits(int const);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif // FIXED_H_
