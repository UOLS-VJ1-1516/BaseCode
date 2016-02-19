#include "Vector2D.h"

/*Este fichero contiene todos los métodos de la clase Vector2D implementados
entre ellos esta sumar, restar, multiplicar, dividir dos vectores y obtener el
tamaño de estos.*/
Vector2D::Vector2D()
{
	m_x = 0;
	m_y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	m_x = x;
	m_y = y;
}

Vector2D::~Vector2D(void)
{
}

float Vector2D::getX()
{
	return m_x;
}

float Vector2D::getY()
{
	return m_y;
}

void Vector2D::setX(float x)
{
	m_x = x;
}

void Vector2D::setY(float y)
{
	m_y = y;
}

Vector2D Vector2D::operator+(const Vector2D & v2) const
{
	return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D Vector2D::operator+=(const Vector2D & v2)
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
	return *this;
}

Vector2D Vector2D::operator-() const
{
	return Vector2D();
}

Vector2D Vector2D::operator-(const Vector2D & v2) const
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
	float distancia = length();
	if (distancia > 0)
	{
		(*this) *= 1 / distancia;
	}
}

Vector2D Vector2D::operator=(const Vector2D & v2)
{
	return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}