#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "LoaderParams.h"
#include "SDL.h"
#include "Vector2D.h"

class GameObject
{
public:
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void onCollision(GameObject* go) = 0;

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

	const char* getId() {
		return m_textureID;
	}

	void setCameraMove(float x) {
		m_position.setX(m_position.getX() + x);
	}

	SDL_Rect getBoundingBox() {
		return m_pBoundingBox;
	}
	
protected:
	int m_width;
	int m_spriteNum;
	int m_height;
	Vector2D m_position = Vector2D(0,0);
	Vector2D m_velocity;
	Vector2D m_acceleration;
	Vector2D m_friction;
	float m_frictionCoeficient;
	float m_maxVelocity;
	int m_currentFrame;
	int m_currentRow;
	const char* m_textureID;
	SDL_Rect m_pBoundingBox;
};

#endif GAMEOBJECT_H