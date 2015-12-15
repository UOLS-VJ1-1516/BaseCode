#pragma once
#include <string>
#include <vector>
//#include "Level.h"
#include "Vector2D.h"

/*class TileLayer : public Layer
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
private:
	int m_numColumns;
	int m_numRows;
	int m_tileSize;
	Vector2D m_position;
	Vector2D m_velocity;
	const std::vector<Tileset> &m_tilesets;
	std::vector<std::vector<int>> m_tileIDs;
};*/
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
	TileLayer(int tileWidth, int tileHeight, const std::vector<Tileset> & tilesets);
	virtual ~TileLayer(void);
	void update();
	void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	Tileset getTilesetByID(int tileID);
private:
	int m_tileWidth; // Ancho de un patrón
	int m_tileHeight; // Alto de un patrón
	int col;
	int row;
	Vector2D m_position; // Posición del mapa
	Vector2D m_velocity;
	static std::vector< Tileset > m_tilesets; // tilesets utilizados en esta capa
	std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posición
};

