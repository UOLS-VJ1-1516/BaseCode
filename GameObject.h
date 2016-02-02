#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL.h"
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
	Vector2D getPosition() {
		return m_position;
	}
	Vector2D getVelocity() {
		return m_velocity;
	}
	int getWidth() {
		return m_width;
	}
	SDL_Rect m_pBoundingBox;
	SDL_Rect getBoundingBox() { return m_pBoundingBox; }
	std::string s_gameObjectID;
	virtual std::string type() { return s_gameObjectID; }
	virtual void onCollision(GameObject* other);
protected:
	int m_width;
	int m_spriteNum;
	int m_height;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	Vector2D m_desacceleration;
	Vector2D m_frictionLeft;
	Vector2D m_frictionRight;
	float m_maxVelocity;
	int m_currentFrame;
	int m_currentRow;
	std::string m_textureID;
	int m_callbackID;
};

#endif 
