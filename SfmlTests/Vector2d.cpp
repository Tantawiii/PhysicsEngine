#include "Vector2d.h"
#include <iostream>

Vector2d::Vector2d():x(1), y(1) {}

Vector2d::Vector2d(float x, float y): x(x), y(y) {}

Vector2d Vector2d::operator+(Vector2d other) {
	return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(Vector2d other) {
	return Vector2d(x - other.x, y - other.y);
}

Vector2d& Vector2d::operator+=(Vector2d other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2d& Vector2d::operator-=(Vector2d other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2d& Vector2d::operator=(Vector2d other) {
	x = other.x;
	y = other.y;
	return *this;
}

bool Vector2d::operator==(Vector2d other) {
	return (x == other.x) && (y == other.y);
}

Vector2d Vector2d::operator*(float a) {
	return Vector2d(x * a, y * a);
}

Vector2d Vector2d::operator*(float a) const {
	return Vector2d(x * a, y * a);
}

Vector2d& Vector2d::operator*=(float a) {
	x *= a;
	y *= a;
	return *this;
}

float Vector2d::Dot(Vector2d other) {
	return (x * other.x + y * other.y);
}


float Vector2d::getMagnitude() {
	return sqrt(x * x + y * y);
}


Vector2d Vector2d::getNormalized() {
	float magnitude = getMagnitude();
	if (magnitude != 0) {
		return Vector2d(x / magnitude, y / magnitude);
	}
	return *this;
}


void Vector2d::normalize() {
	float magnitude = getMagnitude();
	if (magnitude != 0) {
		x /= magnitude;
		y /= magnitude;
	}
}


Vector2d::operator Vector2f() {
	return Vector2f(x, y);
}


Vector2d Vector2d::getNormal() {
	return Vector2d(-y, x);
}


void Vector2d::print() {
	std::cout << "Vector2d(" << x << ", " << y << ")" << std::endl;
}