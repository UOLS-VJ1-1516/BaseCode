#pragma once
#include "math.h"

class Vector2D
{
public:
	Vector2D();
	Vector2D(double x, double y);
	~Vector2D(void);
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	Vector2D operator+(const Vector2D& v2)
		const;
	Vector2D& operator+=(const Vector2D& v2
		);
	Vector2D operator*(double scalar);
	Vector2D& operator*=(double scalar);
	Vector2D operator-() const;
	Vector2D operator-(const Vector2D& v2)
		const;
	Vector2D& operator-=(const Vector2D& v2);
	Vector2D operator/(double scalar);
	Vector2D& operator/=(double scalar);
	float length();
	void normalize();
	Vector2D& operator=(const Vector2D& v2);
private:
	double m_x;
	double m_y;
};