#include "TileLayer.h"
#include "TextureManager.h"
#include "game.h"
#include <iostream>
#include "Camera.h"

TileLayer::TileLayer(int tileWidth, int tileHeight, int map_width, int map_height, const std::vector<Tileset>& tilesets) 
	: m_tileWidth(tileWidth), m_tileHeight(tileHeight),m_tilesets(tilesets), m_position(0,0), m_velocity(0,0)
{
	m_numColumns = Game::Instance()->getVisibleWidth()/ tileWidth;
	m_numRows = Game::Instance()->getVisibleHeight() / tileHeight;
	m_position.setX(0);
	m_position.setY(0);
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_mapWidth = map_width;
	m_mapHeight = map_height;
}

void TileLayer::update(){
	m_position += m_velocity;
}

void TileLayer::render()
{
	int x, y, x2, y2 = 0;
	x = m_position.getX() / m_tileWidth;
	y = m_position.getY() / m_tileHeight;
	x2 = int(m_position.getX()) % m_tileWidth;
	y2 = int(m_position.getY()) % m_tileHeight;
	Vector2D temporalCameraPosition = Camera::Instance()->getPosition();
	int firstColumn = temporalCameraPosition.getX() / m_tileWidth;
	for (int i = 0; i < m_numRows+1; i++)
	{
		for (int j = firstColumn; j < m_numColumns + firstColumn +1;j++)
		{
			int id = m_tileIDs[i][j + x];
			if (id == 0)
			{
				continue;
			}
			
			if (((j * m_tileWidth) - x2) - Camera::Instance()->getPosition().m_x < - m_tileWidth ||
				((j * m_tileHeight) - x2) - Camera::Instance()->getPosition().m_x > Game::Instance()->getVisibleWidth())
			{
				continue;
			}

			Tileset tileset = getTilesetByID(id);
			id--;
			TextureManager::Instance()->drawTile(tileset.name,
				tileset.margin, tileset.spacing, 
				((j * m_tileWidth) - x2) - Camera::Instance()->getPosition().m_x, 
				((i * m_tileHeight) - y2),
				m_tileWidth, m_tileHeight, 
				(id - (tileset.firstGridID - 1)) / tileset.numColumns, 
				(id - (tileset.firstGridID - 1)) % tileset.numColumns, 
				Game::Instance()->getRenderer());
		}
	}

}

void TileLayer::setTileIDs(const std::vector<std::vector<int>>& data)
{
	m_tileIDs = data;
}

Tileset TileLayer::getTilesetByID(int tile)
{
	for (int i = 0; i < m_tilesets.size(); i++)
	{
		if (i + 1 <= m_tilesets.size() - 1)
		{
			if (tile >= m_tilesets[i].firstGridID&&tile < m_tilesets[i + 1].firstGridID)
			{
				return m_tilesets[i];
			}
		}
		else
		{
			return m_tilesets[i];
		}
	}
	Tileset tileset;
	return tileset;

}
