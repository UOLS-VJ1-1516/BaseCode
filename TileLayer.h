#pragma once
#include "Level.h"
#include "Layer.h"
#include "Vector2D.h"
#include <vector>

class TileLayer : public Layer
{
public:
	TileLayer(int tileWidth, int tileHeight, int map_width, int map_height, const std::vector< Tileset> & tilesets);
	virtual void update();
	virtual void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	std::vector<std::vector<int>> getTileIDs() const { return m_tileIDs; }
	void setTileWidth(int tileWidth) { m_tileWidth = tileWidth; }
	int getTileWidth() { return m_tileWidth; }
	int getTileHeight() { return m_tileHeight; }
	int getMapWidth() { return m_mapWidth; }
	int getMapHeight() { return m_mapHeight; }
	void setTileHeight(int tileHeight) { m_tileHeight = tileHeight; }
	Vector2D& getPosition() { return m_position; }
	Tileset getTilesetByID(int tileID);
private:
	int m_tileWidth; // Ancho de un patrón
	int m_tileHeight; // Alto de un patrón
	int m_numColumns;
	int m_numRows;
	int m_mapWidth;
	int m_mapHeight;
	Vector2D m_position; // Posición del mapa
	Vector2D m_velocity;
	const std::vector< Tileset > &m_tilesets; // tilesets utilizados en esta capa
	std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posición
};
