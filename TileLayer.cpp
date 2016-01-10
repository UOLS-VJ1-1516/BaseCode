#include "TileLayer.h"
#include "Game.h"
#include "TextureManager.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset>&tilesets) : m_tileSize(tileSize), m_tilesets(tilesets), m_position(0, 0), m_velocity(0, 0) {
	m_numColumns = (Game::Instance()->getGameWidth() / m_tileSize);
	m_numRows = (Game::Instance()->getGameHeight() / m_tileSize);
	m_position.setX(0);
	m_velocity.setX(0);
	m_position.setY(0);
	m_velocity.setY(0);
}


void TileLayer::update()
{
	if (m_position.getX() / m_tileSize + m_numColumns < m_tileIDs[0].size() && m_position.getY() / m_tileSize + m_numRows < m_tileIDs.size()) {
		m_position += m_velocity;
		m_velocity.setX(0.5);
	}


	
}

void TileLayer::render()
{
	int x, y, x2, y2 = 0;
	x = m_position.getX() / m_tileSize;
	y = m_position.getY() / m_tileSize;
	x2 = int(m_position.getX()) % m_tileSize;
	y2 = int(m_position.getY()) % m_tileSize;

	for (int i = 0; i < m_numRows+1; i++)
	{
		for (int j = 0; j < m_numColumns; j++)
		{
			
			int id = m_tileIDs[i][j + x];
			
			if (id == 0)
			{
				continue;
			}
			Tileset tileset = getTilesetByID(id);
			id--;
			
			TextureManager::Instance()->drawTile(tileset.name.c_str(), tileset.margin, tileset.spacing, (j * m_tileSize) - x2, (i * m_tileSize) - y2,
				m_tileSize, m_tileSize, (id - (tileset.firstGridID - 1)) / tileset.numColumns,
				(id - (tileset.firstGridID - 1)) % tileset.numColumns, Game::Instance()->getRender());
		}
	}
}

void TileLayer::setTileIDs(const std::vector<std::vector<int>>& data)
{
	m_tileIDs = data;
}

Tileset TileLayer::getTilesetByID(int tileID)
{
	for (int i = 0; i < m_tilesets.size(); i++)
	{
		if (i + 1 <= m_tilesets.size() - 1)
		{
			if (tileID >= m_tilesets[i].firstGridID && tileID < m_tilesets[i + 1].firstGridID)
			{
				return m_tilesets[i];
			}
		}
		else
		{
			return m_tilesets[i];
		}
	}
	Tileset tile;
	return tile;
}




