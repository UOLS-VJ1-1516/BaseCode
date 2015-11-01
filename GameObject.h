#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "LoadPar.h"




class GameObject
{
	
public:
	GameObject();
	~GameObject();
	virtual bool load(int x, int y, int width, int height, char* texid) = 0;
	virtual bool load(const LoadPar* lPar) = 0;
	virtual void draw(SDL_Renderer* g_lRenderer)=0;
	virtual void update()=0;
	virtual void clean()=0;
protected:
	int m_width, m_height, m_currentFrame, m_currentRow, m_x, m_y, m_sprits, m_flip; 
	char* m_texid;


};



