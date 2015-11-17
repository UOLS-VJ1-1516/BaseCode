#pragma once
#include "game.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "InputHandler.h"

//Clase abstracta para crear los game objects
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
	const char* m_textureID;
	char* m_fileName;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	//int m_x;
	//int m_y;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_maxVelocity;
	Vector2D m_acceleration;
	Vector2D m_desacceleration;
	Vector2D m_frictionR;
	Vector2D m_frictionL;
	int m_spriteNum;
	int m_rowNum;
};