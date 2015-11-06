#pragma once
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
#include "string"

class LoaderParams
{
public:
	LoaderParams(float x, float y, int width, int height,
		const char* textureID, int currentRow, int sprits, int flip){
		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;
		m_textureID = textureID;
		m_currentRow = currentRow;
		m_num = sprits;
	}
	float getX() const { return m_x; }
	float getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getCurrentRow() const { return m_currentRow; }
	const char* getTextureID() const { return m_textureID; }
	int getSprits() const { return m_num; }
	
private:
	float m_x;
	float m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	const char* m_textureID;
	int m_num;
	
};

#endif LOADERPARAMS_H