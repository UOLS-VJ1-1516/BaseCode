#pragma once
#include "Vector2D.h"
#include <vector>
#include <string>
#include "Layer.h"
//#include "Level.h"

struct Tileset;

class TileLayer : public Layer
{
public:
	TileLayer(int tileSize, const std::vector<Tileset> &tilesets);
	//virtual ~TileLayer(void);
	void update();
	void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);

	void setTileSize(int tileSize) {
		m_tileSize = tileSize;
	}
	std::vector<std::vector<int>> getTileIDs() const { return m_tileIDs; }

	void setNumColumns(int numCols) { m_numColumns = numCols; }
	Vector2D& getPosition() { return m_position; }
	int getTileSize() { return m_tileSize; }
	
	Tileset getTilesetByID(int tileID);
private:

	int m_numRows;
	int m_numColumns;
	int m_tileSize;
	//int m_tileHeight; 
	Vector2D m_position;
	Vector2D m_velocity;
	bool m_isCollider;
	static std::vector<Tileset> m_tilesets;
	std::vector< std::vector< int > > m_tileIDs;
};