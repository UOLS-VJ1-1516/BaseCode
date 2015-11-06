#include "Vector2D.h"

Vector2D::Vector2D(){}

Vector2D::~Vector2D(){}


Vector2D Vector2D::operator+(const Vector2D & v2) const
{
	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D & Vector2D::operator+=(const Vector2D& v2)
{
	m_x += v2.m_x;
	m_y += v2.m_y;
	return *this;
}

Vector2D Vector2D::operator*(float scalar)
{
	return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D & Vector2D::operator*=(float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
}

Vector2D Vector2D::operator-(const Vector2D& v2) const
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}


Vector2D & Vector2D::operator-=(const Vector2D & v2)
{
	m_x -= v2.m_x;
	m_y -= v2.m_y;
	return *this;
}

Vector2D Vector2D::operator/(float scalar)
{
	return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D & Vector2D::operator/=(float scalar)
{
	m_x /= scalar;
	m_y /= scalar;
	return *this;
}

float Vector2D::length()
{
	return sqrt(m_x * m_x + m_y * m_y);
}

void Vector2D::normalize()
{
	float l = length();
	if (l > 0) 
	{
		(*this) *= 1 / l;
	}
}

Vector2D & Vector2D::operator=(const Vector2D & v2)
{
	// TODO: insertar una instrucci�n return aqu�
}


