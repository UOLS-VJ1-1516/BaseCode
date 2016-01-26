#pragma once
#include "GameObject.h"
#include "TileLayer.h"

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
	Vector2D buenaPos;
	float maxJump;
	int speed;
	int direction;
};