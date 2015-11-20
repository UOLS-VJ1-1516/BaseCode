#pragma once

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2(void);
	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);
	Vector2 operator+(const Vector2& v2) const;
	Vector2& operator+=(const Vector2& v2);
	Vector2 operator*(float scalar) const;
	Vector2& operator*=(float scalar);
	Vector2 operator-() const;
	Vector2 operator-(const Vector2& v2) const;
	Vector2& operator-=(const Vector2& v2);
	Vector2 operator/(float scalar);
	Vector2& operator/=(float scalar);
	float length();
	void normalize();
	Vector2& operator=(const Vector2& v2);

private:
	float x;
	float y;
};
