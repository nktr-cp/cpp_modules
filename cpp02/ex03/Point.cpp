#include "Point.h"

// private
Point& Point::operator=(const Point& other) {
	(void)other;
	return *this;
}

// public
Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Fixed x, const Fixed y) : x_(x), y_(y) {}

Point::Point(const Point& other)
: x_(other.getX()),
	y_(other.getY())
{}

Point::~Point() {}

Point Point::operator-(const Point& other) {
	Fixed x = this->getX() - other.getX();
	Fixed y = this->getY() - other.getY();
	return Point(x,y);
}

Fixed Point::getX() const {
	return this->x_;
}

Fixed Point::getY() const {
	return this->y_;
}

