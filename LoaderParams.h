#pragma once
#include "string"
class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, int numSprites, std::string textureID, int callbackID, int animSpeed) :
		m_x(x), m_y(y), m_width(width), m_height(height), m_numsprites(numSprites), m_textureID(textureID), m_callbackID(callbackID), m_animSpeed(animSpeed){}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getNumSprites() const { return m_numsprites; }
	std::string getTextureID() const { return m_textureID; }
	int getCallBackID() const { return m_callbackID; }
	int getAnimSpeed() const { return m_animSpeed; }
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_numsprites;
	std::string m_textureID;
	int m_callbackID;
	int m_animSpeed;
};
