#pragma once
#include "Vector2D.h"
#include <vector>
#include <string>

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};
class TileLayer
{
public:
	TileLayer(int tileWidth, int tileHeight, const std::vector<Tileset> &tilesets);
	virtual ~TileLayer(void);
	void update();
	void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	Tileset getTilesetByID(int tileID);
private:
	
	int m_numRows;
	int m_numColumns;
	int m_tileWidth; // Ancho de un patrón
	int m_tileHeight; // Alto de un patrón
	Vector2D m_position; // Posición del mapa
	Vector2D m_velocity;
	static std::vector< Tileset > m_tilesets; // tilesets utilizados en esta capa
	std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posición
};


