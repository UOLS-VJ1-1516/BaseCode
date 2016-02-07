#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D() {}
Vector2D::Vector2D(float x, float y) {
	m_x = x;
	m_y = y;

}
Vector2D::~Vector2D(void) {}
float Vector2D::getX() { return m_x; }
float Vector2D::getY() { return m_y; }
void Vector2D::setX(float x) { m_x = x; }
void Vector2D::setY(float y) { m_y = y; }

Vector2D Vector2D::operator+(const Vector2D &v2) const {
	return *(new Vector2D(m_x + v2.m_x, m_y + v2.m_y));
}

Vector2D& Vector2D::operator+=(const Vector2D& v2) {
	setX(m_x + v2.m_x);
	setY(m_y + v2.m_y);
	return *this;
}

Vector2D Vector2D::operator-() const {
	return *this;
}
Vector2D Vector2D::operator-(const Vector2D& v2) const {
	return *(new Vector2D(m_x - v2.m_x, m_y - v2.m_y));
}
Vector2D& Vector2D::operator-=(const Vector2D& v2) {
	setX(m_x - v2.m_x);
	setY(m_y - v2.m_y);
	return *this;
}

float Vector2D::length() {
	return sqrt(m_x*m_x + m_y*m_y);
}

Vector2D Vector2D::normalize() {
	float module = length();
	Vector2D ret = Vector2D();
	if (module > 0) {
		ret.m_x = m_x / module;
		ret.m_y = m_y / module;
	}
	else {
		ret.m_x = 0;
		ret.m_y = 0;
	}
	return *this;
}

Vector2D Vector2D::operator*(float scalar)
{
	Vector2D ret = Vector2D();
	ret.m_x = scalar*this->m_x;
	ret.m_y = scalar*this->m_y;
	return ret;
}

Vector2D& Vector2D::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
	Vector2D ret = Vector2D();
	ret.m_x = this->m_x / scalar;
	ret.m_y = this->m_y / scalar;
	return ret;
}

Vector2D & Vector2D::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	return *this;
}