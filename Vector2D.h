#pragma once

#ifndef VECTOR2D
#define VECTOR2D
#include<math.h>

class Vector2D
{
public:

	Vector2D();
	~Vector2D(void);

	Vector2D(float x, float y) : m_x(x), m_y(y) {}
	

	float getX() { return m_x; }
	float getY() { return m_y; }
	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	Vector2D operator+(const Vector2D& v2)const;
	Vector2D& operator+=(const Vector2D& v2);

	Vector2D operator*(float scalar);
	Vector2D& operator*=(float scalar);


	Vector2D operator-(const Vector2D& v2)const;

	Vector2D& operator-=(const Vector2D& v2);

	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);

	float length();
	void normalize();

	Vector2D& operator=(const Vector2D& v2);

private:
	float m_x;
	float m_y;
};

#endif VECTOR2D


