#pragma once
#include "string"

class LoaderParams
{
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::string m_textureID;
	std::string m_fileName;
	int m_spriteNum;
	int m_callbackID;

public:
	LoaderParams(int x, int y, int width, int height, std::string textureID, std::string fileName, int spriteNum, int callbackID) {
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_textureID = textureID;
		m_fileName = fileName;
		m_spriteNum = spriteNum;
		m_callbackID = callbackID;
	}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
	std::string getFileName() const { return m_fileName; }
	int getSpriteNum() const { return m_spriteNum; }
	int getCallbackID() const { return m_callbackID; }
};