#pragma once
#ifndef TILELAYER_H
#define TILELAYER_H
#include "vector"
#include "vector2D.h"

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int width;
	int height;
	int spacing;
	int margin;
	int numColumns;
	//const char* name;
	std::string name;
};

class TileLayer
{
public:
	TileLayer(int tileWidth, int tileHeight, const std::vector< Tileset> & tilesets);
	virtual ~TileLayer(void);
	void update();
	void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	Tileset getTilesetByID(int tileID);
private:
	int m_tileWidth; // Ancho de un patrón
	int m_tileHeight; // Alto de un patrón
	int m_numColumns;
	int m_numRows;
	Vector2D m_velocity;
	Vector2D m_position; // Posición del mapa
	static std::vector< Tileset > m_tilesets; // tilesets utilizados en esta capa
	std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posición
	int col;
	int row;
};
#endif
