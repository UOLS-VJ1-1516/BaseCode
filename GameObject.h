#pragma once
#include "TileLayer.h"
#include "game.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "InputHandler.h"

#include <vector>

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
	Vector2D getVelocity() { return m_velocity; }
	Vector2D getPosition() { return m_position; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	//
	void setCollisionLayers(std::vector<TileLayer*>* layers) {
		pCollisionLayers = layers;
	}
	
protected:
	std::string m_textureID;
	std::string m_fileName;
	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	//int m_x;
	//int m_y;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_maxVelocity;
	Vector2D m_minVelocity;
	Vector2D m_acceleration;
	Vector2D m_desacceleration;
	Vector2D m_frictionR;
	Vector2D m_frictionL;
	int m_spriteNum;
	int m_rowNum;
	int m_callbackID;
	std::vector<TileLayer*>* pCollisionLayers;
};