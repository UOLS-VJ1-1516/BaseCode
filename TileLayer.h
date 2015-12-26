#pragma once
#include <string>
#include <vector>
#include "Vector2D.h"

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;	
	int numColumns;
	std::string name;
	int width;
	int height;
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
	int m_tileWidth; 
	int m_tileHeight; 
	int m_col;
	int m_row;
	Vector2D m_position; 
	Vector2D m_velocity;
	static std::vector< Tileset > m_tilesets; // tilesets utilizados en esta capa
	std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posición
};