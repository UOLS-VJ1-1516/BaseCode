#pragma once

#ifndef LOADERPARAMS_H
#define LOADERPARAMS_H

class LoaderParams {
	public:
		LoaderParams(int x, int y, int width, int height, const char* textureID, int numSprite) : 
			m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID), m_numSprite(numSprite){}
		int getX() const { return m_x;  }
		int getY() const { return m_y;  }
		int getWidth() const { return m_width; }
		int getHeight() const { return m_height; }
		const char* getTextureID() const { return m_textureID; }
		int getNumSprite() const { return m_numSprite; }
		
	private:
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		const char* m_textureID;
		int m_numSprite;
};

#endif
