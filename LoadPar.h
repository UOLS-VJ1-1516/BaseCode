#pragma once
#ifndef LOADPAR_h
#define LOADPAR_H
#include <string>
#include "Vector2D.h"
#pragma once
#include <string>

class LoadPar
{
public:

	LoadPar(int x, int y, int width, int height, int Numsprites, std::string textureID, int callbackID=0, int animSpeed = 0)
	{
		m_x = x;
		m_y = y;
		m_height = height;
		m_width = width;
		m_textureID = textureID;
		m_numsprites = Numsprites;
		m_callbackID = callbackID;
		m_animSpeed=animSpeed;
	}



	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	int getAnimspeed() const { return m_animSpeed; }
	int getCallbackID() const { return m_callbackID; }
	std::string getTextureID() const { return m_textureID; }
	int getNumSprites() const { return m_numsprites; }

private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_callbackID;
	int m_animSpeed;
	int m_friction;
	int m_numsprites;
	std::string m_textureID;
	
	

};
#endif LOADPAR_H