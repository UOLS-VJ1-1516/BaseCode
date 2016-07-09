#pragma once
#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H
#include <string>

class LoaderParams
{
	public:
		LoaderParams(int x, int y, int width, int height, char* textureID, int currentRow, int sprite, int callBackID){
			
			m_x = x;
			m_y = y;
			m_height = height;
			m_width = width;
			m_textureID = textureID;
			m_sprite = sprite;
			m_callBackID = callBackID;
		}

		int getX() const { return m_x; }
		int getY() const { return m_y; }
		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }
		char* getTextureID() const { return m_textureID; }
		int getSprits() const { return m_sprite; }
		int getCurrentRow() const { return m_currentRow; }
		int getCallbackID() const { return m_callBackID; }

	private:
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		int m_currentRow;
		int m_sprite;
		char*  m_textureID;
		int m_callBackID;
};

#endif LOADERPARAMS_H