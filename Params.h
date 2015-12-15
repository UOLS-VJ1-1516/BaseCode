#pragma once
#include "string"


class Params
{
public:
	Params(float x, float y, int width, int height, std::string textureID, std::string fileName, int spriteNum, int rowNum, int flip, int callbackID)
		: m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID), m_fileName(fileName), m_spriteNum(spriteNum), m_rowNum(rowNum), m_flip(flip), m_callbackID(callbackID) {}
	float getX() const { return m_x; }
	float getY() const { return m_y; }
	float m_x;
	float m_y;


	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getSpriteNum() const { return m_spriteNum; }
	int getRowNum() const { return m_rowNum; }
	int getFlip() const { return m_flip; }
	int getCallbackID() const { return m_callbackID; }
	int m_width;
	int m_height;
	int m_spriteNum;
	int m_rowNum;
	int m_flip;
	int m_callbackID;

	std::string m_textureID;
	std::string m_fileName;
	std::string getTextureID() const { return m_textureID; }
	std::string getFileName() const { return m_fileName; }




	
};