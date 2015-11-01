#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "texturemanager.h"
#include "LoadPar.h"
#include "game.h"





class GameObject
{
	
public:
	GameObject();
	~GameObject();
	virtual bool load(int x, int y, int width, int height, char* texid) = 0;
	virtual bool load(const LoadPar* lPar) = 0;
	virtual void draw(SDL_Renderer* g_lRenderer)=0;
	virtual void draw() = 0;
	virtual void update()=0;
	virtual void clean()=0;
protected:
	int m_width, m_height, m_currentFrame, m_currentRow, m_x, m_y, m_sprits, m_flip; 
	
	char* m_texid;


};
#endif GAMEOBJECT_h

