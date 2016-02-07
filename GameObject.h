#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject
{
public:
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0; 	
	virtual void onCollsion(GameObject* other) = 0;
	Vector2D getVelocity() {
		return m_velocity;
	}
	Vector2D getPosition() {
		return m_position;
	}
	int getWidth() {
		return m_width;
	}
	int getHeight() {
		return m_height;
	}
	void clean();

protected:
	std::string m_textureID;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	int m_sprits;
	int m_flip;
	
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_maxVelocity;
	Vector2D m_acceleration;
	Vector2D m_friction;

};
#endif GAMEOBJECT_H