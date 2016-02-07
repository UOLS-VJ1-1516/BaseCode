#pragma once
#include "string"
#include <vector>
#include "Layer.h"

class TileLayer;

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
class Player;
class Level
{
public:
	virtual ~Level() {}
	//Level() {}
	void update();
	void render();
	std::vector<Tileset>* getTilesets() { return &m_tilesets; }
	std::vector<Layer*>* getLayers() { return &m_layers; }
	std::vector<TileLayer*>* getCollisionLayers() { return &m_collisions; }
	Player* getPlayer() { return m_pPlayer; }
	void setPlayer(Player* pPlayer) { m_pPlayer = pPlayer; }
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	std::vector<TileLayer*> m_collisions;
	friend class LevelParser;

	Level() {}
	Player* m_pPlayer;
};