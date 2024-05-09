#include "Point.h"
// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle

static Fixed sign(Point p1, Point p2, Point p3) {
	Point a = p1 - p3;
	Point b = p2 - p3;

	Fixed f1 = a.getX() * b.getY();
	Fixed f2 = a.getY() * b.getX();

	return f1 - f2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float d1 = sign(point, a, b).toFloat();
	float d2 = sign(point, b, c).toFloat();
	float d3 = sign(point, c, a).toFloat();

	return ((d1 > 0 && d2 > 0 && d3 > 0)
					|| (d1 < 0 && d2 < 0 && d3 < 0));
}