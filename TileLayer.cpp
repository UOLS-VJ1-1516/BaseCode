#include "TileLayer.h"
#include "game.h"
#include "TextureManager.h"

TileLayer::TileLayer(int tileWidth, int tileHeight, const std::vector<Tileset>& tilesets) 
	: m_tileWidth(tileWidth), m_tileHeight(tileHeight),m_tilesets(tilesets), m_position(0,0), m_velocity(0,0)
{
	m_numColumns = (Game::Instance()->getVisibleWidth() / m_tileWidth);
	m_numRows = (Game::Instance()->getVisibleHeight() / m_tileHeight);
	m_position.setX(0);
	m_position.setY(0);
	m_velocity.setX(0);
	m_velocity.setY(0);
}

TileLayer::~TileLayer(void)
{
}

void TileLayer::update()
{
	m_position += m_velocity;
	if(m_position.getX()>=1920-Game::Instance()->getVisibleWidth())
		m_velocity.setX(0);
}

void TileLayer::render()
{
	int x, y, x2, y2 = 0;
	x = m_position.getX() / m_tileWidth;
	y = m_position.getY() / m_tileHeight;
	x2 = int(m_position.getX()) % m_tileWidth;
	y2 = int(m_position.getY()) % m_tileHeight;

	for (int i = 0; i < m_numRows; i++)
	{
		for (int j = 0; j < m_numColumns+1; j++)
		{
			int id = m_tileIDs[i][j + x];
			if (id == 0)
			{
				continue;
			}
			Tileset tileset = getTilesetByID(id);
			id--;
			TextureManager::Instance()->drawTile(tileset.name, 
				0, 0,
				(j * m_tileWidth) - x2, (i * m_tileHeight) - y2,
				m_tileWidth,
				m_tileHeight, 
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
			if (tile >= m_tilesets[i].firstGridID&&tile < m_tilesets[i +
				1].firstGridID)
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
