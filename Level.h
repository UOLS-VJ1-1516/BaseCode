#pragma once

#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>
#include "Layer.h"
#include "Player.h"
#include "CollisionObject.h"

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

	std::vector<Layer*>* getCollisionLayers() {
		return &m_CollisionsLayer;
	}

	Player* getPlayer() { 
		return m_pPlayer; 
	}

	void setPlayer(Player* pPlayer) { 
		m_pPlayer = pPlayer; 
	}
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
	std::vector<Layer*> m_CollisionsLayer;
	friend class LevelParser;
	Level();
	Player* m_pPlayer;
};
#endif
