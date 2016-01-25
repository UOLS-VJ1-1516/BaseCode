#pragma once
#include "Layer.h"
#include "Vector2D.h"
#include <vector>
#include "Tileset.h"
#include "Game.h"
#include "textureManager.h"
/*
es la capa que gestiona los tiles
*/

class TileLayer : public Layer
{
public:
	TileLayer(int tileSize, const std::vector<Tileset> &tilesets);
	virtual void update();
	virtual void render();
	void setTileIDs(const std::vector<std::vector<int>>& data)
	{
		m_tileIDs = data;
	}
	void setTileSize(int tileSize)
	{
		m_tileSize = tileSize;
	}
	Tileset getTilesetByID(int tileID);

	std::vector<std::vector<int>> getTileIDs() { return m_tileIDs; }
	Vector2D getPosition(){ return m_position; }
	int getTileSize() { return m_tileSize; }

private:
	int m_numColumns;
	int m_numRows;
	int m_tileSize;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D camPos;
	const std::vector<Tileset> &m_tilesets;
	std::vector<std::vector<int>> m_tileIDs;
	
};
