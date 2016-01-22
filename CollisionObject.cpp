#pragma once
#include "CollisionObject.h"
#include <vector>
#include "TileLayer.h"


CollisionObject::CollisionObject() {

}
CollisionObject::~CollisionObject() {

}
void CollisionObject::load(const LoaderParams* pParams) {

}
void CollisionObject::draw()
{

}
void CollisionObject::update()
{
}
void CollisionObject::clean()
{

}

void CollisionObject::onCollsion(GameObject * other)
{
}

bool CollisionObject::isCollisionWithTile()
{
	for (std::vector<TileLayer*>::const_iterator it = CollisionObject::m_pCollisionLayers->begin(); it != CollisionObject::m_pCollisionLayers->end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		int x, y, tileColumn, tileRow, tileid = 0;
		x = pTileLayer->getPosition().getX() / pTileLayer->getTileWith();
		y = pTileLayer->getPosition().getY() / pTileLayer->getTileHeight();
		m_TileWith = pTileLayer->getTileWith();
		m_TileHeight = pTileLayer->getTileHeight();

		if (getVelocity().getX() >= 0 && getVelocity().getY() >= 0) //abajo y derecha
		{
			tileColumn = ((getPosition().getX() + getWidth() - m_collisionMargin) / pTileLayer->getTileWith());
			tileRow = ((getPosition().getY() + getHeight()) / pTileLayer->getTileHeight());
			if ((tileRow + y) >= pTileLayer->getTileIDs().size() || (tileColumn + x) >= pTileLayer->getTileIDs()[0].size()) {
				m_CollisionDirection = 2;
				return true;//si se sale del mapa
			}
			tileid = pTileLayer->getTileIDs()[tileRow + y][tileColumn + x-1];
		}
		else if (getVelocity().getX() < 0 && getVelocity().getY() < 0)//arriba e izquierda
		{
			tileColumn = ((getPosition().getX() + m_collisionMargin) / pTileLayer->getTileWith());
			tileRow = (getPosition().getY() / pTileLayer->getTileHeight());
			if ((tileRow + y) >= pTileLayer->getTileIDs().size() || (tileColumn + x) >= pTileLayer->getTileIDs()[0].size()) {
				m_CollisionDirection = 2;
				return true;//si se sale del mapa
			}
			tileid = pTileLayer->getTileIDs()[tileRow + y][tileColumn + x+1];
		}
		else if (getVelocity().getX() >= 0 && getVelocity().getY() < 0)//arriba y derecha
		{
			tileColumn = ((getPosition().getX() + getWidth() - m_collisionMargin) / pTileLayer->getTileWith());
			tileRow = (getPosition().getY() / pTileLayer->getTileHeight());
			if ((tileRow + y) >= pTileLayer->getTileIDs().size() || (tileColumn + x) >= pTileLayer->getTileIDs()[0].size()) {
				m_CollisionDirection = 4;
				return true;//si se sale del mapa
			}
			tileid = pTileLayer->getTileIDs()[tileRow + y][tileColumn + x-1];
		}
		else if (getVelocity().getX() < 0 && getVelocity().getY() >= 0)//abajo e izquierda
		{
			tileColumn = ((getPosition().getX() + m_collisionMargin) / pTileLayer->getTileWith());
			tileRow = ((getPosition().getY() + getHeight()) / pTileLayer->getTileHeight());
			if ((tileRow + y) >= pTileLayer->getTileIDs().size() || (tileColumn + x) >= pTileLayer->getTileIDs()[0].size()) {
				m_CollisionDirection = 2;
				return true;//si se sale del mapa
			}
			tileid = pTileLayer->getTileIDs()[tileRow + y][tileColumn + x+1];
		}

		if (tileid != 0) //se trata de un tile que no es de aire, por lo tanto hay colision. 
		{
			m_CollisionDirection = CollisionDirection(tileColumn, tileRow, pTileLayer->getTileWith(), pTileLayer->getTileHeight());
			return true;
		}
	}
	m_CollisionDirection = 0;
	return false;
}

int CollisionObject::CollisionDirection(int tileColumn, int tileRow, float TileWith, float TileHeight)
{
	float leftwall = TileWith*tileColumn;
	float topwall = TileWith*tileRow;
	float collisiondistanceX = getWidth() - 2*(m_collisionMargin - leftwall);
	float collisiondistanceY = getHeight() - 2*(m_collisionMargin - topwall);
	if (absolute(collisiondistanceX) == 0 && absolute(collisiondistanceY) == 0) {
		return 0;
	}
	if (getVelocity().getX() > 0) { // voy a la derecha
		if (absolute(collisiondistanceX) / getVelocity().getX() > absolute(collisiondistanceY) / getVelocity().getY()) { //impacto a mi derecha (playeR)
			return 4;
		}else {
			if (getVelocity().getY() > 0) {
				return 1; //impacto superior.
			}
			else {
				return 3; //impacto inferior.
			}
		}
	}else {
		if (absolute(collisiondistanceX) / getVelocity().getX() > absolute(collisiondistanceY) / getVelocity().getY()) { //impacto a mi izquierda (playeR)
			return 2;
		}
		else {
			if (getVelocity().getY() > 0) {
				return 1; //impacto superior.
			}
			else {
				return 3; //impacto inferior.
			}
		}
	}
}

float CollisionObject::absolute(float a) {
	return a < 0 ? -a : a;
}
