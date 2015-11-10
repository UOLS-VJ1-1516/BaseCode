#pragma once
class Vector2D
{
public:
	Vector2D();
	Vector2D(float, float);
	~Vector2D();

	float X;
	float Y;

	Vector2D operator+(const Vector2D&) const;
	Vector2D& operator+=(const Vector2D&);

	Vector2D operator-() const;
	Vector2D operator-(const Vector2D&) const;
	Vector2D& operator-=(const Vector2D&);

	Vector2D operator*(float);
	Vector2D operator*(const Vector2D&) const;
	Vector2D& operator*=(float);
	Vector2D& operator*=(const Vector2D&);

	Vector2D operator/(float);
	Vector2D& operator/=(float);

	float lenght();
	void normalize();
};

