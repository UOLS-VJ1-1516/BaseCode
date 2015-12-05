#pragma 
#include "Tileset.h"
#include "Vector2D.h"
#include <vector>

class TileLayer
{
public:
	TileLayer(int tileWidth, int tileHeight, const std::vector< Tileset> & tilesets);
	virtual ~TileLayer(void);
	void update();
	void render();
	void setTileIDs(const std::vector< std::vector< int > >& data);
	Tileset getTilesetByID(int tileID);

	int m_tileSize;
	int m_numRows;
	int m_numColumnas;
private:
	int m_tileWidth; // Ancho de un patr�n
	int m_tileHeight; // Alto de un patr�n
	Vector2D m_position; // Posici�n del mapa
	const std::vector< Tileset > &m_tilesets; // tilesets utilizados en esta capa
	std::vector< std::vector< int > > m_tileIDs; // ids de los tiles en cada posici�n
};


