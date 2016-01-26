#pragma once
#include "math.h"

class Vector2D {
	public:
		Vector2D();
		Vector2D(float x, float y);
		~Vector2D(void);

		float getX();
		float getY();
		void setX(float x);
		void setY(float y);

		Vector2D operator+(const Vector2D& v2) const;
		Vector2D& operator+=(const Vector2D& v2);
		
		Vector2D operator*(float scalar);
		Vector2D& operator*=(float scalar);

		Vector2D operator-() const;
		Vector2D operator-(const Vector2D& v2)const;
		Vector2D& operator-=(const Vector2D& v2);

		Vector2D operator/(float scalar);
		Vector2D& operator/=(float scalar);
		float length();
		void normalize();

		Vector2D operator=(const Vector2D& v2);

		float m_x;
		float m_y;
};