#include "Vector2.h"
#include "math.h"

Vector2::Vector2() { x = 0, y = 0; }

Vector2::Vector2(float x, float y) {
	setX(x);
	setY(y);
}

Vector2::~Vector2(void) {
}

float Vector2::getX() const {
	return x;
}

float Vector2::getY() const {
	return y;
}

void Vector2::setX(float x) {
	Vector2::x = x;
}

void Vector2::setY(float y) {
	Vector2::y = y;
}

Vector2 Vector2::operator+(const Vector2 & v2) const {
	return *new Vector2(getX() + v2.getX(), getY() + v2.getY());
}

Vector2 & Vector2::operator+=(const Vector2 & v2) {
	setX(getX() + v2.getX());
	setY(getY() + v2.getY());
	return *this;
}

Vector2 Vector2::operator*(float scalar) const {
	return *new Vector2(getX() + scalar, getY() * scalar);
}

Vector2 & Vector2::operator*=(float scalar) {
	setX(getX() * scalar);
	setY(getY() * scalar);
	return *this;
}

Vector2 Vector2::operator-() const {
	return Vector2::operator*(-1);
}

Vector2 Vector2::operator-(const Vector2 & v2) const {
	return *new Vector2(getX() - v2.getX(), getY() - v2.getY());
}

Vector2 & Vector2::operator-=(const Vector2 & v2) {
	setX(getX() - v2.getX());
	setY(getY() - v2.getY());
	return *this;
}

Vector2 Vector2::operator/(float scalar) {
	return *new Vector2(getX() / scalar, getY() / scalar);
}

Vector2 & Vector2::operator/=(float scalar) {
	setX(getX() / scalar);
	setY(getY() / scalar);
	return *this;
}

float Vector2::length() {
	return sqrt(pow(getX(), 2) + pow(getY(), 2));
}

void Vector2::normalize() {
	*this /= Vector2::length();
}

Vector2 & Vector2::operator=(const Vector2 & v2) {
	setX(v2.getX());
	setY(v2.getY());
	return *this;
}