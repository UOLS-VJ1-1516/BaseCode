#pragma once
#include "vector"
#include "Vector2D.h"
#include "Level.h"

class TileLayer : public Layer
{
public:
	TileLayer(int tileWidth, int tileHeight, const std::vector< Tileset> & tilesets);
	virtual ~TileLayer(void);
	virtual void update();
	virtual void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	void setTileWidth(int tileWidth) { m_tileWidth = tileWidth; }
	void setTileHeight(int tileHeight) { m_tileHeight = tileHeight; }
	Tileset getTilesetByID(int tileID);
private:
	int m_tileWidth; // Ancho de un patrón
	int m_tileHeight; // Alto de un patrón
	int m_numColumns;
	int m_numRows;
	Vector2D m_position; // Posición del mapa
	Vector2D m_velocity;
	const std::vector< Tileset > &m_tilesets; // tilesets utilizados en esta capa
	std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posición
};
