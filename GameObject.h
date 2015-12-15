#pragma once
#include "game.h"
#include "Params.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "InputHandler.h"


class GameObject{




public:

	GameObject();


	virtual ~GameObject();
	virtual void load(const Params* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;


	std::string m_textureID;
	std::string m_fileName;


	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	int m_spriteNum;
	int m_rowNum;
	int m_flip;
	int m_callbackID;


	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_maxVelocity;
	Vector2D m_acceleration;
	Vector2D m_friction;
};
