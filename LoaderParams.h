#pragma once
#include "string"

class LoaderParams
{
	public:
		LoaderParams(float x, float y, int width, int height, const char* textureID, char* fileName, int spriteNum, int rowNum)
			: m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID), m_fileName(fileName),m_spriteNum(spriteNum), m_rowNum(rowNum){}
		float getX() const { return m_x; }
		float getY() const { return m_y; }
		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }
		const char* getTextureID() const { return m_textureID; }
		char* getFileName() const { return m_fileName; }
		int getSpriteNum() const { return m_spriteNum; }
		int getRowNum() const { return m_rowNum; }
		float getVelX() const { return m_velX;  }
		float getVelY() const { return m_velY; }
		float getMaxVel() const { return m_maxVel;  }
		double getFriction() const { return m_friction;  }

	private:
		float m_x;
		float m_y;
		int m_width;
		int m_height;
		const char* m_textureID;
		char* m_fileName;
		int m_spriteNum;
		int m_rowNum;
		float m_velX;
		float m_velY;
		float m_maxVel;
		float m_friction;
};
