#include "CollisionObject.h"
#include "Camera.h"


CollisionObject::CollisionObject()
{
}


CollisionObject::~CollisionObject()
{
}

bool CollisionObject::isCollisionWithTileLeft() {
	// iterate through collision layers
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it) {
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		// get this layers position
		Vector2D layerPos = pTileLayer->getPosition();
		int x, y, tileColumn, tileRow, tileid = 0;
		// calculate position on tile map
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		tileColumn = ((getPosition().getX() + Camera::Instance()->getPosition().getX() + getWidth()) / pTileLayer->getTileSize());
		tileRow = ((getPosition().getY() + getHeight()) / pTileLayer->getTileSize());
		tileid = tiles[tileRow + y][tileColumn + x]; //Li restem 1 a la y perque quan estiguem asobre la plataforma no ens doni colisio

		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}
bool CollisionObject::isCollisionWithTileTop() {
	// iterate through collision layers
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it) {
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		// get this layers position
		Vector2D layerPos = pTileLayer->getPosition();
		int x, y, tileColumn, tileRow, tileid = 0;
		// calculate position on tile map
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		if (getVelocity().getY() > 0) //Adalt
		{
			tileColumn = (getPosition().getX() / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight()) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y][tileColumn + x];//Li restem 1 a la y perque quan estiguem asobre la plataforma no ens doni colisio
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}
bool CollisionObject::isCollisionWithTileBottom() {
	// iterate through collision layers
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it) {
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		// get this layers position
		Vector2D layerPos = pTileLayer->getPosition();
		int x, y, tileColumn, tileRow, tileid = 0;
		// calculate position on tile map
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		tileColumn = ((getPosition().getX() + getWidth()) / pTileLayer->getTileSize());
		tileRow = ((getPosition().getY() + getHeight()) / pTileLayer->getTileSize());
		tileid = tiles[tileRow + y][tileColumn + x]; //Li restem 1 a la y perque quan estiguem asobre la plataforma no ens doni colisio

		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}

bool CollisionObject::isCollisionWithTileRight() {
	// iterate through collision layers
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it) {
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		// get this layers position
		Vector2D layerPos = pTileLayer->getPosition();
		int x, y, tileColumn, tileRow, tileid = 0;
		// calculate position on tile map
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();

		if (getVelocity().getX() > 0) //dreta
		{
			tileColumn = ((getPosition().getX() + Camera::Instance()->getPosition().getX() + getWidth()) / pTileLayer->getTileSize());
			tileRow = (getPosition().getY() / pTileLayer->getTileSize());
			tileid = tiles[tileRow+y][tileColumn + x];//Li restem 1 a la y perque quan estiguem asobre la plataforma no ens doni colisio
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}


bool CollisionObject::isCollisionWithTile() {
	// iterate through collision layers
	for (std::vector<TileLayer*>::const_iterator it = m_pCollisionLayers->begin(); it != m_pCollisionLayers->end(); ++it){
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		// get this layers position
		Vector2D layerPos = pTileLayer->getPosition();
		int x, y, tileColumn, tileRow, tileid = 0;
		// calculate position on tile map
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();
		
		if (getVelocity().getX() > 0 || getVelocity().getY() > 0) //Adalt i dreta
		{
			tileColumn = ((getPosition().getX() + Camera::Instance()->getPosition().getX() + getWidth()) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight())/ pTileLayer->getTileSize());
			tileid = tiles[tileRow + y - 1][tileColumn + x - 1.5];//Li restem 1 a la y perque quan estiguem asobre la plataforma no ens doni colisio
		}
		else if (getVelocity().getX() < 0 || getVelocity().getY() < 0) // Abaix i esquerra
		{
			tileColumn = ((getPosition().getX() + Camera::Instance()->getPosition().getX() + getWidth()) / pTileLayer->getTileSize());
			tileRow = ((getPosition().getY() + getHeight()) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y - 1][tileColumn + x - 4]; //Li restem 1 a la y perque quan estiguem asobre la plataforma no ens doni colisio
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			return true;
		}
	}
	return false;
}

