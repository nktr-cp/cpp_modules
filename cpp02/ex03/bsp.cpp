#include "Point.h"
// https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

static float area(Point const p1, Point const p2, Point const p3) {
	float x1 = p1.getX().toFloat();
	float y1 = p1.getY().toFloat();
	float x2 = p2.getX().toFloat();
	float y2 = p2.getY().toFloat();
	float x3 = p3.getX().toFloat();
	float y3 = p3.getY().toFloat();

	return std::fabs(((x1*(y2-y3)) + x2*(y3-y1) + x3*(y1-y2)) * 0.5f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float A = area(a, b, c);
	float A1 = area(point, b, c);
	float A2 = area(a, point, c);
	float A3 = area(a, b, point);

	return std::fabs(A - (A1 + A2 + A3)) < 1e-6;
}