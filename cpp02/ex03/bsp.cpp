#include "Point.h"
// https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

static float cross(Point const a, Point const b, Point const c) {
	float ax = b.getX().toFloat() - a.getX().toFloat();
	float ay = b.getY().toFloat() - a.getY().toFloat();
	float bx = c.getX().toFloat() - a.getX().toFloat();
	float by = c.getY().toFloat() - a.getY().toFloat();
	return ax * by - ay * bx;
}

static bool not_on_edge_or_vertex(Point const &a, Point const &b, Point const &c, Point const &p) {
	float ab = cross(a, b, p);
	float bc = cross(b, c, p);
	float ca = cross(c, a, p);
	return std::fabs(ab) > 1e-6 && std::fabs(bc) > 1e-6 && std::fabs(ca) > 1e-6;
}

static float area(Point const p1, Point const p2, Point const p3) {
	return std::fabs(cross(p1, p2, p3)) * 0.5f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	if (!not_on_edge_or_vertex(a, b, c, point)) return false;

	float A = area(a, b, c);
	float A1 = area(point, b, c);
	float A2 = area(a, point, c);
	float A3 = area(a, b, point);

	return std::fabs(A - (A1 + A2 + A3)) < 1e-6;
}