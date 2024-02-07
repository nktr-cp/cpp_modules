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

		Fixed(const Fixed &);

		~Fixed();

		Fixed& operator=(const Fixed &);
		friend std::ostream& operator<<(std::ostream&, const Fixed&);

		int getRawBits(void) const;
		void setRawBits(int const);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif // FIXED_H_