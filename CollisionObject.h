#pragma once
#include "GameObject.h"
#include <vector>
//#include "TileLayer.h"

class TileLayer;

class CollisionObject : public GameObject
{
public:
	CollisionObject();
	~CollisionObject();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void setm_pCollisionLayers(std::vector<TileLayer*>* collisionlayers) {
		m_pCollisionLayers = collisionlayers;
	}
protected:
	bool isCollisionWithTile(Vector2D newPos);
	int m_collisionMargin;
	Vector2D buenaPos;
	float topeJump;
private:
	std::vector<TileLayer*>*m_pCollisionLayers;
};

