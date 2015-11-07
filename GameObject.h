#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
//#include "SDL.h"
//#include "String"
#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	int m_width;
	int m_spriteNum;
	int m_height;
	//int m_x;
	//int m_y;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	Vector2D m_friction;
	Vector2D m_maxVelocity;
	int m_currentFrame;
	int m_currentRow;
	const char* m_textureID;
};

#endif 
