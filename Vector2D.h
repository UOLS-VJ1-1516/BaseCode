#pragma once
#include "math.h"

class Vector2D {
public:

	Vector2D();
	Vector2D(float , float y);
	~Vector2D(void);
	float getX();
	float getY();
	float m_x;
	float m_y;
	void setX(float x);
	void setY(float y);
	float length();
	void normalize();

	Vector2D operator+(const Vector2D& v2) const;
	Vector2D operator+=(const Vector2D& v2);
	Vector2D operator*(float scalar);
	Vector2D& operator*=(float scalar);
	Vector2D operator-() const;
	Vector2D operator-(const Vector2D& v2)const;
	Vector2D& operator-=(const Vector2D& v2);
	Vector2D operator/(float scalar);
	Vector2D& operator/=(float scalar);
	Vector2D operator=(const Vector2D& v2);

	
};