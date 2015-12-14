#pragma once

#include <vector>
#include "Tileset.h"
#include "Layer.h"

class Level
{
public:
	void update();
	void render();
	std::vector<Tileset>* getTilesets();
	std::vector<Layer*>* getLayers();
private:
	//guarda los tilesets (coleccion de tiles, imagen grande)
	std::vector<Tileset> m_tilesets;

	//guarda los layer (capas) del juego, por ejemplo: un capa background y otro de objects(player, enemig)
	std::vector<Layer*> m_layers;

	//solo se puede instanciar por clase levelparser
	friend class LevelParser;
	//no deja que pueda instancial el level el mismo
	Level();
};