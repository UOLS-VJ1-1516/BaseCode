#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void load(int x, int y, int width, int height,
		std::string textureID) = 0;
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:
	std::string m_textureID;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_sprits;
	int m_flip;
	


};
#endif GAMEOBJECT_H