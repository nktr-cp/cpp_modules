#include "Fixed.h"
#include "Point.h"

Point::Point() : x_(Fixed(0.0f)), y_(Fixed(0.0f)) {}

Point::Point(const float x, const float y) : x_(Fixed(x)), y_(Fixed(y)) {}

Point::Point(const Point& other)
: x_(other.getX()),
	y_(other.getY())
{}

Point& Point::operator=(const Point& other) {
	(void)other;
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return this->x_;
}

Fixed Point::getY() const {
	return this->y_;
}

