#pragma once
#include <string>
#include <vector>
#include <string>
#include "Layer.h"
#include "Player.h"
#include "CollisionManager.h"

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


class Level
{
public:
	~Level() {}
	void update();
	void render();
	std::vector<Tileset>* getTilesets()
	{
		return &m_tilesets;
	}

	std::vector<Layer*>* getLayers()
	{
		return &m_layers;
	}

	std::vector<TileLayer*>* getCollisionLayers() {
		return &m_CollisionLayers;
	}

	

private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	std::vector<TileLayer*> m_CollisionLayers;
	Player *m_Player;
	std::vector<ObjectLayer*>*objectLayers;
	CollisionManager m_CollisionManager;
	friend class LevelParser;
	Level();
};