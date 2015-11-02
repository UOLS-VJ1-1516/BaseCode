#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	const char* m_textureID;
	char* m_fileName;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_spriteNum;
	int m_rowNum;
};
