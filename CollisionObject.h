#pragma once
#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#include "GameObject.h"
#include "TileLayer.h"

class TileLayer;


class CollisionObject : public GameObject
{
	
public:
	CollisionObject();
	virtual ~CollisionObject();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
protected:
	bool isCollisionWithTile(Vector2D newPos);
	int m_collisionMargin;
	double saltoMax;
	int run = 3;
	int lado = 1;
};

#endif