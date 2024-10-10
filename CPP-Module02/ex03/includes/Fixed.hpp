#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
private:
	int								_fixedValue;
	static const int	_raw = 8;

public:
	Fixed(void);
	Fixed(const int iraw);
	Fixed(const float fraw);
	Fixed(Fixed const &src);
	~Fixed(void);

// assignment
	Fixed &operator=(Fixed const &rhs);

// Comparison
	bool operator>(const Fixed &nbr);
	bool operator<(const Fixed &nbr);
	bool operator<=(const Fixed &nbr);
	bool operator>=(const Fixed &nbr);
	bool operator==(const Fixed &nbr);
	bool operator!=(const Fixed &nbr);
	
// Arithmetic
	Fixed operator+(const Fixed &nbr);
	Fixed operator-(const Fixed &nbr);
	Fixed operator*(const Fixed &nbr);
	Fixed operator/(const Fixed &nbr);
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed &operator++(void);
	Fixed &operator--(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &oStream, const Fixed &nbr);

#endif //! FIXED_HPP