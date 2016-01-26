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
	virtual void clean() = 0;
	virtual void onCollision(GameObject* other) = 0;

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
protected:
	int m_width;
	int m_spriteNum;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	const char* m_textureID;
	Vector2D m_position;
	Vector2D m_velocity;
	float m_velocityMax;
	float m_frictionCoeficient;
	Vector2D m_acceleration;
	Vector2D m_friction;
	int flip;
};

#endif