#pragma once
class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height) : m_x(x), m_y(y), m_width(width), m_height(height) {}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }

private:
	int m_x, m_y, m_width, m_height;
};