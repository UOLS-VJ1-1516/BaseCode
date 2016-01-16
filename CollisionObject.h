#pragma once

/*#include "GameObject.h"
#include "TileLayer.h"
#include <string>

class CollisionObject : public GameObject
{
public:
	CollisionObject();
	virtual ~CollisionObject();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void checkPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*> &collisionLayers);
protected:
	bool isCollisionWithTile();
	int m_collisionMargin; // Margen horizontal para evitar colisión.
						   // Diferente para cada tipo de objeto
private:
	std::vector< TileLayer* >* m_pCollisionLayers;// Puntero a todas las
												  //capas de patrones con colisión
};*/
