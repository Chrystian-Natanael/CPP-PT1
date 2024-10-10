#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int _fixedValue;
	static const int _raw = 8;

public:
	Fixed(void);
	Fixed(Fixed const &src);

	~Fixed(void);
	Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif // !FIXED_HPP