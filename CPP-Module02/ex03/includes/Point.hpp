#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const	_x;
	Fixed const	_y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	~Point(void);

	Point &operator=(const Point &rhs);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

#endif //! POINT_HPP