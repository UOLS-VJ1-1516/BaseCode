#pragma once
#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H
#include "GameObject.h"
#include "TileLayer.h"
#include <vector>

class TileLayer;
class CollisionObject : public GameObject
{
public:
	CollisionObject();
	virtual ~CollisionObject();
	virtual void load(const LoadPar* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();


	void setCollisionLayers(std::vector< TileLayer* >* pCollisionLayers) {
		m_pCollisionLayers = pCollisionLayers;
	}
	
	bool isCollisionWithTile();  //Protected debe ser
protected:
	
	int m_collisionMargin; // Margen horizontal para evitar colisión.
						   // Diferente para cada tipo de objeto

	int m_TileWith;
	int m_tileSize;
	int m_TileHeight;
private:
	std::vector< TileLayer* >* m_pCollisionLayers;// Puntero a todas las
												  //capas de patrones con colisión
};
#endif