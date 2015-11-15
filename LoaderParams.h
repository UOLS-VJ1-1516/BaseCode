#pragma once

#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, const char* textureID, int spriteNum,int speedX,int speedY ,int maxSpeed, int friction):
	m_x(x),m_y(y),m_width(width),m_height(height),m_num(spriteNum),m_textureID(textureID),m_speedX(speedX),m_speedY(speedY),m_maxSpeed(maxSpeed),m_friction(friction){
		
	}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	const char* getTextureID() const { return m_textureID; }
	int getNum() const { return m_num; }
	
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_num;
	const char* m_textureID;
	int m_speedX,m_speedY;
	int m_maxSpeed;
	int m_friction;
};
#endif