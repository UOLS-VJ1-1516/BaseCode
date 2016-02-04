#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <string>
#include "SDL_image.h"
#include "Vector2D.h"
#include "LoadPar.h"



class GameObject
{
	
public:
	GameObject() {};
	virtual ~GameObject() {};

	//virtual void load(float x, float y, int width, int height, std::string texid) = 0;
	virtual void load(const LoadPar* lPar) = 0;
	virtual void draw(SDL_Renderer* g_lRenderer)=0;
	virtual void draw() = 0;
	virtual void update()=0;
	virtual void clean()=0;
	int getWidth() {return m_width;	}
	int getHeight() {return m_height;}
	Vector2D getPosition() {
		return m_position;
	}
	
	
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	Vector2D m_maxacceleration;
	Vector2D m_maxaccelerationneg;
	Vector2D m_friction;
	

	
	int m_width;
	int	m_height;
	int	m_currentFrame;
	int	m_currentRow;
	int	m_sprits;
	int	m_flip;
	int m_anchopantalla;
	int m_altopantalla;
	std::string m_texid;
	const char* m_textureID;


};
#endif GAMEOBJECT_h

