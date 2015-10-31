#pragma once
#include "SDL.h"
#include "String"
#include "LoaderParams.h"


class GameObject
{
public:
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	int m_width;
	int spriteNum;
	int m_height;
	int m_x;
	int m_y;
	int m_currentFrame;
	int m_currentRow;
	const char* m_textureID;
};

