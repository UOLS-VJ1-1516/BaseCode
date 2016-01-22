#pragma once
#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#include "GameObject.h"
#include <vector>

class TileLayer;
class CollisionObject : public GameObject
{
public:
	CollisionObject();
	virtual ~CollisionObject();
	virtual void load(const LoaderParams* pParams) = 0;
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void onCollsion(GameObject* other);
	void setCollisionLayers(std::vector< TileLayer* >* pCollisionLayers) {
		m_pCollisionLayers = pCollisionLayers;
	}
	void setCollisionMargin(int pCollitionMargin) {
		m_collisionMargin = pCollitionMargin;
	}
	int getCollisionDirection() {
		return m_CollisionDirection;
	}
	float getTileWith() {
		return m_TileWith;
	}
	float getTileHeight() {
		return m_TileHeight;
	}
protected:
	bool isCollisionWithTile();
	int CollisionDirection(int tileColumn, int tileRow, float TileWith, float TileHeight);
	int m_collisionMargin;
	int m_CollisionDirection;
	int m_TileWith;
	int m_TileHeight;
private:
	std::vector< TileLayer* >* m_pCollisionLayers;
	float absolute(float a);
};
#endif