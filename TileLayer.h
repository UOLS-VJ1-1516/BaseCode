#pragma once
#include <vector>
#include "Vector2D.h"
#include "Layer.h"
#include "Level.h"

class TileLayer : public Layer
{

public:
	TileLayer(int tileSize, const std::vector<Tileset> &tilesets);
	virtual void update();
	virtual void render();

	void setTileIDs(const std::vector<std::vector<int>>& data) { m_tileIDs = data; }
	std::vector<std::vector<int>> getTileIDs() const { return m_tileIDs; }
	void setTileSize(int tileSize) { m_tileSize = tileSize; }
	int getTileSize() { return m_tileSize; }
	Tileset getTilesetByID(int tileID);
	Vector2D& getPosition() { return m_position; }


private:
	int m_numColumns;
	int m_numRows;
	int m_tileSize;

	Vector2D m_position;
	Vector2D m_velocity;

	const std::vector<Tileset> &m_tilesets;
	std::vector<std::vector<int>> m_tileIDs;
};