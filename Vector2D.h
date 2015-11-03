#pragma once
class Vector2D
{
public:
	Vector2D();
	Vector2D(int, int);
	~Vector2D();

	int X;
	int Y;

	Vector2D operator+(const Vector2D&) const;
	Vector2D& operator+=(const Vector2D&);

	Vector2D operator-() const;
	Vector2D operator-(const Vector2D&) const;
	Vector2D& operator-=(const Vector2D&);

	Vector2D operator*(float);
	Vector2D& operator*=(float);

	Vector2D operator/(float);
	Vector2D& operator/=(float);

	float lenght();
	void normalize();
};

