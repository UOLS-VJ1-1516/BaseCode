#pragma once
#include "GameObject.h"
#include "vector"
#include "TileLayer.h"
class CollisionObject : public GameObject
{
public:
	CollisionObject();
	virtual ~CollisionObject();
	virtual void load(const LoaderParams* pParams)=0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	void setCollisionLayers(std::vector< TileLayer* >* pCollisionLayers) {
		m_pCollisionLayers = pCollisionLayers;
	}
protected:
	bool isCollisionWithTile();
	int m_collisionMargin; // Margen horizontal para evitar colisión.
						   // Diferente para cada tipo de objeto
private:
	std::vector< TileLayer* >* m_pCollisionLayers;// Puntero a todas las
												  
};
