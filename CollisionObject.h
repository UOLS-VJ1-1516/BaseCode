#pragma once
#include "GameObject.h"
#include "TileLayer.h"
#include "game.h"

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
	bool isCollisionWithTile(Vector2D BPos);
	int m_collisionMargin; // Margen horizontal para evitar colisión.
						   // Diferente para cada tipo de objeto
	Vector2D APos;
	float maxJump;
private:
	//std::vector< TileLayer* >* m_pCollisionLayers;// Puntero a todas las
												  //capas de patrones con colisión
	
};
