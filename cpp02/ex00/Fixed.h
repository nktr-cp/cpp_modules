#ifndef FIXED_H_
#define FIXED_H_

class Fixed {
	private:
		int	value_;
		static const int fractionalBits = 8;
	public:
		Fixed();

		Fixed(const int);

		Fixed(const Fixed&);

		~Fixed();

		Fixed& operator=(const Fixed&);

		int getRawBits(void) const;
		void setRawBits(int const);
};

#endif // FIXED_H_