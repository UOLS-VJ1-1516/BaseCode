#pragma once
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, const char* textureID, int numSprites, float speed_x, float speed_y,float speed_max, float friction) {
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_textureID = textureID;
		m_num = numSprites;
		m_speed_x = speed_x;
		m_speed_y = speed_y;
		m_speedMax = speed_max;
		m_friction = friction;

	}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	const char* getTextureID() const { return m_textureID; }
	int getNum() const { return m_num; }
	float getSpeed_x() const { return m_speed_x; }
	float getSpeed_y() const { return m_speed_y; }
	float getSpeedMax() const { return m_speedMax; }
	float getFriction() const { return m_friction; }
	
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_num;
	const char* m_textureID;
	float m_speed_x;
	float m_speed_y;
	float m_speedMax;
	float m_friction;
};

#endif LOADERPARAMS_H
