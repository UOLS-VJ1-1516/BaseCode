#pragma once
#include "SDL.h"
#include "Params.h"
#include "Vector2D.h"

class GameObject {
public:

	GameObject();
	virtual ~GameObject();
	virtual void load(const Params* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	int m_width;
	int m_spriteNum;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	const char* m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	Vector2D m_desacceleration;
	Vector2D m_frictionLeft;
	Vector2D m_frictionRight;
	Vector2D m_maximaVelocidad;
	
};

