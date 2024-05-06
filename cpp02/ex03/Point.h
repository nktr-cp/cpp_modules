#ifndef POINT_H_
#define POINT_H_

#include "Fixed.h"
#include <cmath>

class Point {
	private:
		const Fixed x_;
		const Fixed y_;
	public:
		Point();

		Point(const float, const float);

		Point(const Point&);

		~Point();

		Point& operator=(const Point&);
		Point operator-(const Point&);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_H_