#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "string"
#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{
public:

	virtual void load(const LoaderParams* pParams) = 0;

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	int m_width;
	int m_spriteNum;
	int m_height;
	int m_x;
	int m_y;
	int m_currentFrame;
	int m_currentRow;
	int m_speed;
	const char* m_textureID;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_maxVelocity;
	Vector2D m_acceleration;
	Vector2D m_friction;
};

#endif GAMEOBJECT_H