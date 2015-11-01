#pragma once

class LoaderParams
{
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	char* m_textureID;
	int m_spriteNum;

public:
	LoaderParams(int x, int y, int width, int height, char* textureID, int spriteNum) {
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_textureID = textureID;
		m_spriteNum = spriteNum;
	}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	char* getTextureID() const { return m_textureID; }
	int getSpriteNum() const { return m_spriteNum; }
};