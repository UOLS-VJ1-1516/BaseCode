#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "LoaderParams.h"

class GameObject {
	public:
		virtual void load(const LoaderParams* pParams) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;

	protected:
		int m_x;
		int m_y;
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		const char* m_textureID;
		int m_numSprite;
};

#endif