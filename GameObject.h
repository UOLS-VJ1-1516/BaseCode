#pragma once
#include "game.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "TileLayer.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	virtual void load(const LoaderParams* pParams)=0;
	virtual void draw()=0;
	virtual void update() = 0;
	virtual void clean();
	void setCollisionLayers(std::vector<TileLayer*>* layers) {
		m_pCollisionLayers = layers;
	}
	bool isCollision() { return collision; }
	void setCollision(bool type) { collision = type; }
	Vector2D m_position;
	Vector2D m_velocity;
	int m_width;
	int m_height;
protected:
	bool collision = false;
	Vector2D m_maxVelocity;
	Vector2D m_acceleration;
	Vector2D m_friction;
	int m_currentFrame;
	int m_currentRow;
	int m_numsprites;
	std::string m_textureID;
	int m_callbackID;
	std::vector<TileLayer*>* m_pCollisionLayers;
};