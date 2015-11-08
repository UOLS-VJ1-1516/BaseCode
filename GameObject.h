#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include "LoadPar.h"
#include "Vector2D.h"


class GameObject
{
	
public:
	
	virtual void load(float x, float y, int width, int height, std::string texid) = 0;
	virtual void load(const LoadPar* lPar) = 0;
	virtual void draw(SDL_Renderer* g_lRenderer)=0;
	virtual void draw() = 0;
	virtual void update()=0;
	virtual void clean()=0;
	
	
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	float x;
	float y;


	int m_width;
	int	m_height;
	int	m_currentFrame;
	int	m_currentRow;
	int	m_sprits;
	int	m_flip;
	std::string m_texid;


};
#endif GAMEOBJECT_h

