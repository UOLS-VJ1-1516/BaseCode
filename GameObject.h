#pragma once
#include "SDL.h"
#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void load(const LoaderParams* pParams)=0;
	virtual void draw()=0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_maxVelocity;
	Vector2D m_acceleration;
	Vector2D m_friction;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	int m_numsprites;
	std::string m_textureID;

	int m_callbackID;
};