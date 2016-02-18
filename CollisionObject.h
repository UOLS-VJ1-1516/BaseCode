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
	
	int m_collisionMargin; // Margen horizontal para evitar colisión.
						   // Diferente para cada tipo de objeto
	bool isCollisionWithTile(); //protected
	bool isCollisionWithRight(); //protected
	bool isCollisionWithUp(); //protected
	bool isCollisionWithDown(); //protected
	bool isCollisionWithLeft(); //protected
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
};
#endif