#pragma once
#include "string"

//Clase que controla los diferentes parametros que tendran los game objects al crearse
class LoaderParams
{
	public:
		LoaderParams(float x, float y, int width, int height, std::string textureID, int spriteNum, int rowNum, int flip, int callbackID)
			: m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID), m_spriteNum(spriteNum), m_rowNum(rowNum), m_flip(flip), m_callbackID(callbackID) {}
		float getX() const { return m_x; }
		float getY() const { return m_y; }
		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }
		std::string getTextureID() const { return m_textureID; }
		int getSpriteNum() const { return m_spriteNum; }
		int getRowNum() const { return m_rowNum; }
		int getFlip() const { return m_flip; }
		int getCallbackID() const { return m_callbackID;  }
	private:
		float m_x;
		float m_y;
		int m_width;
		int m_height;
		std::string m_textureID;
		int m_spriteNum;
		int m_rowNum;
		int m_flip;
		int m_callbackID;
};