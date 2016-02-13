#include "TileLayer.h"
#include "game.h"


TileLayer::TileLayer(int tileSize, const std::vector<Tileset> &tilesets, int width) : m_tileSize(tileSize), m_tilesets(tilesets), m_position(0, 0), m_velocity(0, 0), m_width( width)
{
	m_numColumns = (Game::Instance()->getAncho() / m_tileSize);
	m_numRows = (Game::Instance()->getAlto() / m_tileSize);
}

void TileLayer::update()
{

	m_position += m_velocity;
	m_velocity.setX(0);
}

void TileLayer::render()
{
	int x, y, x2, y2 = 0;
	x = m_position.getX() / m_tileSize;
	y = m_position.getY() / m_tileSize;
	x2 = int(m_position.getX()) % m_tileSize;
	y2 = int(m_position.getY()) % m_tileSize;
	

	//Lo hago generico.
	if (x > m_width-101) {
		x2 = 0;
		x = m_width-101;
	}

	
	for (int i = 0; i < m_numRows+1; i++)
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
			
			TextureManager::Instance()->drawTile(tileset.name, tileset.margin, tileset.spacing, (j * m_tileSize) - x2, (i *
				m_tileSize) - y2, m_tileSize, m_tileSize, (id - (tileset.firstGridID - 1)) / tileset.numColumns, (id -
					(tileset.firstGridID - 1)) % tileset.numColumns, Game::Instance()->GetRenderer());
		}
	}
}

Tileset TileLayer::getTilesetByID(int tileID)
{
	for (int i = 0; i < m_tilesets.size(); i++)
	{
		if (i + 1 <= m_tilesets.size() - 1)
		{
			if (tileID >= m_tilesets[i].firstGridID&&tileID < m_tilesets[i +
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
	//std::cout << "did not find tileset, returning empty tileset\n";
	Tileset t;
	return t;
}