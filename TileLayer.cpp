#include "TileLayer.h"
#include "Game.h"
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
	m_col = (Game::Instance()->getwidthWindow() / m_tileWidth);
	m_row = (Game::Instance()->getHeightWindow() / m_tileHeight);
}

TileLayer::~TileLayer(void)
{
}

void TileLayer::update()
{	
	int range_x = m_position.getX() / m_tileWidth + m_col + 1;
	int range_y = m_position.getY() / m_tileHeight + m_row;

	if  (range_x < m_tileIDs[0].size() && range_y < m_tileIDs.size()) 
	{
		m_position += m_velocity;
		m_velocity.setX(1);
	}
}

void TileLayer::render()
{
	int x, y, x2, y2 = 0;
	int pos_x, pos_y, current_row, current_frame;

	x = m_position.getX() / m_tileWidth;
	y = m_position.getY() / m_tileHeight;
	x2 = int(m_position.getX()) % m_tileWidth;
	y2 = int(m_position.getY()) % m_tileHeight;

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col + 1; j++)
		{
			int id = m_tileIDs[i][j + x];
			if (id == 0)	continue;
			
			Tileset tileset = getTilesetByID(id);
			id--;
			pos_x = (j * m_tileWidth) - x2;
			pos_y = (i * m_tileHeight) - y2;
			current_row = (id - (tileset.firstGridID - 1)) / tileset.numColumns * m_tileHeight;
			current_frame = (id - (tileset.firstGridID - 1)) % tileset.numColumns;
			
			TextureManager::Instance()->drawFrame(tileset.name.c_str(), pos_x, pos_y , m_tileWidth, m_tileHeight, current_row, current_frame, Game::Instance()->getRenderer(),0);
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
				return m_tilesets[i];			
		}
		else return m_tilesets[i];
	}

	Tileset t;
	return t;
}