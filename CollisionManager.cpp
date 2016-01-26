/*#include "CollisionManager.h"

void CollisionManager::checkPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*> &collisionLayers)
{
	// iterate through collision layers
	for (std::vector<TileLayer*>::const_iterator it =
		collisionLayers.begin(); it != collisionLayers.end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer ->getTileIDs();
		// get this layers position
		Vector2D layerPos = pTileLayer->getPosition();
		int x, y, tileColumn, tileRow, tileid = 0;
		// calculate position on tile map
		x = layerPos.getX() / pTileLayer->getTileWidth();
		y = layerPos.getY() / pTileLayer->getTileHeight();
		// if moving forward or upwards
		if (pPlayer->m_velocity.getX() >= 0 || pPlayer ->m_velocity.getY() >= 0)
		{
			tileColumn = ((pPlayer->m_position.getX() + pPlayer->m_width) / pTileLayer->getTileWidth());
			tileRow = ((pPlayer->m_position.getY() + pPlayer->m_height) / pTileLayer->getTileHeight());
			tileid = tiles[tileRow + y][tileColumn + x];
		}
		else if (pPlayer->m_velocity.getX() < 0 || pPlayer ->m_velocity.getY() < 0) // if moving backwards or downwards
		{
			tileColumn = pPlayer->m_position.getX() / pTileLayer ->getTileWidth();
			tileRow = pPlayer->m_position.getY() / pTileLayer ->getTileHeight();
			tileid = tiles[tileRow + y][tileColumn + x];
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			//pPlayer->collision();
		}
	}
}*/