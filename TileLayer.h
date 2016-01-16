#pragma once

#ifndef TILELAYER_H
#define TILELAYER_H
#include <string>
#include <vector>
#include "Level.h"
#include "Vector2D.h"

class TileLayer : public Layer
{
public:
	TileLayer(int tileWidth, int tileHeight, const std::vector<Tileset> & tilesets);
	virtual ~TileLayer(void);
	virtual void update();
	virtual void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	Tileset getTilesetByID(int tileID);
	int col;
	int row;
	
	int getTileWith() {
		return m_tileWidth;
	}
	int getTileHeight() {
		return m_tileHeight;
	}
	Vector2D getPosition() {
		return m_position;
	}
	std::vector<std::vector<int>> getTileIDs(){
		return m_tileIDs;
	}
private:
	int m_tileWidth; // Ancho de un patrón
	int m_tileHeight; // Alto de un patrón
	std::vector<std::vector<int>> m_tileIDs;
	Vector2D m_position; // Posición del mapa
	Vector2D m_velocity;
	static std::vector< Tileset > m_tilesets; // tilesets utilizados en esta capa
};

#endif