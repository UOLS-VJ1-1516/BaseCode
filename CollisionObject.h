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
	void recorrerFilaSuperior(TileLayer * pTileLayer, int fila, int columnaIzq, int columnaDer, int offSetTileIndexX, int offSetTileIndexY, bool izq);
	void recorrerFilaInferior(TileLayer * pTileLayer, int fila, int columnaIzq, int columnaDer, int offSetTileIndexX, int offSetTileIndexY, bool izq);
	void recorrerColumnaDerecha(TileLayer * pTileLayer, int columna, int filaIzq, int filaDer, int offSetTileIndexX, int offSetTileIndexY, bool arriba);
	void recorrerColumnaIzquierda(TileLayer * pTileLayer, int columna, int filaArriba, int filaAbajo, int offSetTileIndexX, int offSetTileIndexY, bool arriba);
	void CollisionObject::buscarColisionesDerechaArriba(TileLayer* pTileLayer);
	void CollisionObject::buscarColisionesDerechaAbajo(TileLayer* pTileLayer);
	void CollisionObject::buscarColisionesIzquierdaArriba(TileLayer* pTileLayer);
	void CollisionObject::buscarColisionesIzquierdaAbajo(TileLayer* pTileLayer);
	int m_collisionMargin;
	int m_CollisionDirection;
	int m_TileWith;
	int m_TileHeight;
	bool m_stopArriba;
	bool m_stopAbajo;
	bool m_stopDerecha;
	bool m_stopIzquierda;

	Vector2D m_stopPositionArriba;
	Vector2D m_stopPositionAbajo;
	Vector2D m_stopPositionDerecha;
	Vector2D m_stopPositionIzquierda;

	float m_energyX;
	float m_energyY;
private:
	std::vector< TileLayer* >* m_pCollisionLayers;
	void prohibidoIrHaciaArriba(int col, int fil);
	void prohibidoIrHaciaAbajo(int col, int fil);
	void prohibidoIrHaciaDerecha(int col, int fil);
	void prohibidoIrHaciaIzquierda(int col, int fil);
	float absolute(float a);
};
#endif