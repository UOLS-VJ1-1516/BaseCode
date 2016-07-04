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
	virtual void update(Vector2D pos);
	virtual void clean();
	
	bool getCollision() { return coli; }
	void setCollision(bool colis) {
		coli = colis;
	}

	void setCollisionLayers(std::vector< TileLayer* >* pCollisionLayers) {
		m_pCollisionLayers = pCollisionLayers;
	}
	void setDerecha(bool estado) {
		derecha = estado;
	}
	void setIzquierda(bool estado) {
		izquierda = estado;
	}
	void setArriba(bool estado) {
		arriba = estado;
	}
	void setAbajo(bool estado) {
		abajo = estado;
	}
	bool getDerecha() {
		return derecha;
	}
	bool getIzquierda() {
		return izquierda;
	}
	bool getAbajo() {
		return abajo;
	}
	bool getArriba() {
		return arriba;
	}
	
	
protected:
	bool coli = false;
	int m_collisionMargin; // Margen horizontal para evitar colisión.
						   // Diferente para cada tipo de objeto
	bool isCollisionWithTile(); //protected
	bool isCollisionWithRight(); //protected
	bool isCollisionWithUp(); //protected
	bool isCollisionWithDown(GameObject* pPlayer); //protected
	bool isCollisionWithLeft(); //protected
	bool isCollisionEnemyWithDown(GameObject* enemy);
	bool isCollisionEnemyWithLeft(GameObject* enemy);
	bool isCollisionEnemyWithRight(GameObject* enemy);
	bool checkCollision(GameObject* enemy);

	bool isCollisionMetaWithRight(GameObject *meta);
	int m_TileWith;
	int m_tileSize;
	bool derecha = false;
	bool izquierda = false;
	bool arriba = false;
	bool abajo = false;
	int m_TileHeight;
	
private:
	std::vector< TileLayer* >* m_pCollisionLayers;// Puntero a todas las
												  //capas de patrones con colisión
	GameObject* mEnemy;
	GameObject*  mMeta;
	Vector2D MiCaja[3];
};
#endif