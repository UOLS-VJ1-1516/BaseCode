#pragma once
#ifndef TILELAYER_H
#define TILELAYER_H
#include "vector"
#include "vector2D.h"
#include "Level.h"
#include "Layer.h"

//struct Tileset
//{
//	int firstGridID;
//	int tileWidth;
//	int tileHeight;
//	int width;
//	int height;
//	int spacing;
//	int margin;
//	int numColumns;
//	//const char* name;
//	std::string name;
//};

class TileLayer : public Layer
{
public:
	TileLayer(int tileWidth, int tileHeight, const std::vector< Tileset> & tilesets);
	virtual ~TileLayer(void);
	virtual void update();
	virtual void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	Tileset getTilesetByID(int tileID);
	int getTileWith() {
		return m_tileWidth;
	}
	int getTileHeight() {
		return m_tileHeight;
	}
	Vector2D getPosition() {
		return m_position;
	}
	std::vector<std::vector<int>> getTileIDs() {
		return m_tileIDs;
	}
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
