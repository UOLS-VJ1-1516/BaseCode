#include "TileLayer.h"
#include "Game.h"

TileLayer::TileLayer(int tileWidth, int tileHeight, const std::vector<Tileset>& tilesets) : m_tileSize(m_tileHeight*m_tileWidth), m_tilesets(tilesets), m_position(0, 0)
{
	m_numRows = ((Game::Instance()->getGameHeight() / m_tileSize) + 1);
}

void TileLayer::render()
{
	int x, y = 0;
	x = m_position.getX() / m_tileSize;
	y = m_position.getY() / m_tileSize;


}

Tileset TileLayer::getTilesetByID(int tileID)
{
	for (int i = 0; i < m_tilesets.size(); i++) {
		if (i + 1 <= m_tilesets.size() - 1) {
			if (tileID >= m_tilesets[i].firstGridID && tileID < m_tilesets[i + 1].firstGridID) {
				return m_tilesets[i];
			}
			
		}
		else {
			return m_tilesets[i];
		}
	}

	return Tileset();
}



