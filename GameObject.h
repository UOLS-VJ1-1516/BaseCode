#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "LoaderParams.h"
#include "Vector2D.h"
#include "SDL.h"

class GameObject
{
	public:
		GameObject() {};
		virtual void load(const LoaderParams* pParams) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;

		Vector2D& getPosition() { return m_position; }
		int getWidth() { return m_width; }
		int getHeight() { return m_height; }


	protected:
	
		int m_width;
		int m_height;
		int m_currentFrame;
		int m_currentRow;
		int m_sprite;
		//const char* m_textureID;
		std::string m_textureID;
		Vector2D m_position;
		Vector2D m_velocity;
		Vector2D m_maxVelocity;
		Vector2D m_acceleration;
		Vector2D m_friction;
		
		
};

#endif GAMEOBJECT_H