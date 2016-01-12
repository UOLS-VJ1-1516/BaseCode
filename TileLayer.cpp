#include "TileLayer.h"
#include "game.h"
#include "TextureManager.h"

std::vector<Tileset> TileLayer::m_tilesets = std::vector<Tileset>();

TileLayer::TileLayer(int tileWidth, int tileHeight, const std::vector<Tileset>& tilesets) : m_position(0, 0), m_velocity(0, 0)
{
	m_tilesets = tilesets;
	m_tileHeight = tileHeight;
	m_tileWidth = tileWidth;
	m_position.setX(0);
	m_position.setY(0);
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_numCol = (Game::Instance()->getWindowWidth() / m_tileWidth)+1;
	m_numRow = (Game::Instance()->getWindowHeight() / m_tileHeight)+1;
}

TileLayer::~TileLayer(void)
{
}

void TileLayer::update()
{
	if (m_position.getX() / m_tileWidth + m_numCol + 1 < m_tileIDs[0].size() && m_position.getY() / m_tileHeight + m_numRow < m_tileIDs.size()) {//con esto nos evitamos salirnos del array
		m_position += m_velocity;
		m_velocity.setX(1);
	}
}

void TileLayer::render()
{
	int x, y, x2, y2 = 0;
	x = m_position.getX() / m_tileWidth;
	y = m_position.getY() / m_tileHeight;
	x2 = int(m_position.getX()) % m_tileWidth;
	y2 = int(m_position.getY()) % m_tileHeight;

	for (int i = 0; i < m_numRow; i++)
	{
		for (int j = 0; j < m_numCol + 1; j++)
		{
			int id = m_tileIDs[i][j + x];
			if (id == 0)
			{
				continue;
			}
			Tileset tileset = getTilesetByID(id);
			id--;
			TextureManager::Instance()->drawTileset(tileset.name.c_str(), tileset.margin, tileset.spacing, (j * m_tileWidth) - x2, (i * m_tileHeight) - y2,
				m_tileWidth, m_tileHeight, (id - (tileset.firstGridID - 1)) / tileset.numColumns,
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
	Tileset t;
	return t;
}
