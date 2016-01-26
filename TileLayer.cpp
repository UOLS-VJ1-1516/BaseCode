#include "TileLayer.h"
#include "Game.h"
#include "TextureManager.h"
#include "Camera.h"

std::vector<Tileset> TileLayer::m_tilesets = std::vector<Tileset>();

TileLayer::TileLayer(int tileSize, const std::vector<Tileset>&tilesets) : m_tileSize(tileSize), m_position(0, 0), m_velocity(0, 0) {
	m_numColumns = (Game::Instance()->getGameWidth() / m_tileSize);
	m_numRows = (Game::Instance()->getGameHeight() / m_tileSize);
	m_position.setX(0);
	m_velocity.setX(0);
	m_position.setY(0);
	m_velocity.setY(0);
	//isCollider = true;
	m_tilesets = tilesets;
	m_tileSize = tileSize;
}


void TileLayer::update()
{
	//if (m_position.getX() / m_tileSize + m_numColumns < m_tileIDs[0].size() && m_position.getY() / m_tileSize + m_numRows < m_tileIDs.size()) {
		//m_position += m_velocity;
		//m_velocity.setX(0.2);
	//if (m_position.getX() / m_tileSize + m_numColumns < m_tileIDs[0].size()){
	  //  m_position = Camera::Instance()->getPosition();
		//m_position.setX(m_position.getX() + Camera::Instance()->getPosition().getX() + m_numColumns);
		//m_position.setY(Camera::Instance()->getPosition().getY());
	//}
	//m_position = Camera::Instance()->getPosition();
	//m_position.setX(m_position.getX() + Camera::Instance()->getPosition().getX() + m_numColumns);
	//m_position.setY(Camera::Instance()->getPosition().getY());
}

void TileLayer::render()
{
	
	int x, y, x2, y2 = 0;
	x = m_position.getX() / m_tileSize;
	y = m_position.getY() / m_tileSize;
	Vector2D tempCamPos = Camera::Instance()->getPosition();
	x2 = tempCamPos.getX();
	y2 = int(m_position.getY()) % m_tileSize;
	
	int firstCol = tempCamPos.getX() / m_tileSize;
	for (int i = 0; i < m_numRows+1; i++)
	{
		int col = 0;
		for (int j = firstCol; j < firstCol + m_numColumns; j++)
		{
			/*if (j + x < 0 || j + x > m_tileIDs[0].size() - 1 || i > m_tileIDs.size() - 1) {
				col++;
				continue;
			}*/
			int id = m_tileIDs[i][j + x];
			
			if (id == 0)
			{
				col++;
				continue;
			}
			Tileset tileset = getTilesetByID(id);
			id--;
			
			TextureManager::Instance()->drawTile(tileset.name.c_str(), tileset.margin, tileset.spacing, (j * m_tileSize) - x2, (i * m_tileSize) - y2,
				m_tileSize, m_tileSize, (id - (tileset.firstGridID - 1)) / tileset.numColumns,
				(id - (tileset.firstGridID - 1)) % tileset.numColumns, Game::Instance()->getRender());
			col++;
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




