#include "TileLayer.h"
#include <iostream>
#include <string>
using namespace std;

TileLayer::TileLayer(int tileSize, const
	std::vector<Tileset> &tilesets) : m_tileSize(tileSize),
	m_tilesets(tilesets)
{
	m_position.setX(0);
	m_position.setY(0);
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_numColumns = (Game::Instance()->getScreenWidth() + m_tileSize);
	m_numColumns = m_numColumns / m_tileSize;
	m_numRows = (Game::Instance()->getScreenHeight() / m_tileSize);
}

void TileLayer::update()
{
	if (m_position.getX() < 1100) 
	{
		m_position += m_velocity;
		m_velocity.setX(1);
	}
	else {
		//m_position += m_velocity;
		//m_velocity.setX(-1);
	}
}

void TileLayer::render()
{
	int x, y, x2, y2 = 0;
	x = m_position.getX() / m_tileSize;
	y = m_position.getY() / m_tileSize;
	
	//x2 = int(m_position.getX()) % m_tileSize;
	//y2 = int(m_position.getY()) % m_tileSize;

	x2 = int(m_position.getX()) % m_tileSize;
	y2 = int(m_position.getY()) % m_tileSize;

	//parsear numero de filas
	for (int i = 0; i < m_numRows; i++)
	{
		//parsear filas que hay cada columna
		for (int j = 0; j < m_numColumns; j++)
		{
			//conseguir el id actual
			int id = m_tileIDs[i][j + x];
			//para id == 0 no dibujamos nada
			if (id == 0)
			{
				continue;
			}
			//conseguir el tile en posicion actual
			Tileset tileset = getTilesetByID(id);
			id--;
			// dibujamos el tile
			//(id, margen, spacing, x,y,width, height, currentRoww, currentFrame, SDL_REnderer)
			TextureManager::Instance()->drawTile(tileset.name, 1, 1,
				(j * m_tileSize) - x2, (i * m_tileSize) - y2, m_tileSize,
				m_tileSize, (id - (tileset.firstGridID - 1)) /
				tileset.numColumns, (id - (tileset.firstGridID - 1)) %
				tileset.numColumns, Game::Instance()->getRenderer());
		}
	}
}

//retornar un tile
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
	std::cout << "did not find tileset, returning empty tileset\n";
	Tileset t;
	return t;
}