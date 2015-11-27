#pragma once
#include <string>

class LoaderParams
{
public:

	LoaderParams(int x, int y, int width, int height, int spriteNum, std::string textureID, int callbackID) /*:
		m_x(x), m_y(y), m_width(width), m_height(height), m_num(spriteNum), m_textureID(textureID), m_callbackID(callbackID){}*/
	{
		m_x = x;
		m_y = y;
		m_height = height;
		m_width = width;
		m_textureID = textureID;
		m_num = spriteNum;
		m_callbackID = callbackID;
	}
	


	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getCallbackID() const { return m_callbackID; }
	std::string getTextureID() const { return m_textureID; }
	int getNum() const { return m_num; }

private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_num;
	std::string m_textureID;
	int m_callbackID;
	int m_animSpeed;
	int m_friction;

};
