#pragma once
#include "Vector2D.h"
#include "LoaderParams.h"
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
	public:
		virtual void load(const LoaderParams* pParams) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;
	protected:
		GameObject();
		virtual ~GameObject();
		Vector2D m_position;
		Vector2D m_velocity;
		Vector2D m_maxVelocity;
		Vector2D m_acceleration;
		Vector2D m_friction;
		int m_currentRow;
		int m_currentFrame;
		LoaderParams* pParams;
};
#endif GAMEOBJECT_H
