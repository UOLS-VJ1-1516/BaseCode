#include "TileLayer.h"
#include "Game.h"
#include "TextureManager.h"
#include "Camera.h"

std::vector<Tileset> TileLayer::m_tilesets = std::vector<Tileset>();

TileLayer::TileLayer(int tileWidth, int tileHeight, const std::vector<Tileset>& tilesets) : m_position(0, 0), m_velocity(0, 0)
{
	m_tilesets = tilesets;
	m_tileHeight = tileHeight;
	m_tileWidth = tileWidth;
	col = (Game::Instance()->getwidthWindow() / 16);
	row = (Game::Instance()->getHeightWindow() / m_tileHeight);
	state = true;
}

TileLayer::~TileLayer(void)
{
}

void TileLayer::update()
{
	if (state) {
		m_position += m_velocity;
		m_velocity.setX(4);
	}	
}

void TileLayer::render()
{	
		int x, y, x2, y2 = 0;
		x = m_position.getX() / m_tileWidth;
		y = m_position.getY() / m_tileWidth;
		x2 = int(m_position.getX()) % m_tileWidth;
		y2 = int(m_position.getY()) % m_tileWidth;		
		for (int i = 0; i < row ; i++)
		{
			for (int j = 0; j <  col+4; j++)
			{
				int id = 0;
				if (x + j > 63) {
					state = false;
					id = m_tileIDs[i + y][63];				
				}
				else {
					//state = true;
					id = m_tileIDs[i + y][j + x];					
				}
				
				if (id == 0)
				{
					continue;
				}
				Tileset tileset = getTilesetByID(id);
				id--;
				TextureManager::Instance()->drawTile(tileset.name, tileset.margin, tileset.spacing, ((j * m_tileWidth) - x2) - TheCamera::Instance()->getPosition().getX()/16, ((i * m_tileWidth) - y2), m_tileWidth, m_tileWidth, (id - (tileset.firstGridID - 1)) / tileset.numColumns, (id - (tileset.firstGridID - 1)) % tileset.numColumns, Game::Instance()->getRenderer());
				//x = TheCamera::Instance()->getPosition().getX() / m_tileWidth;
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