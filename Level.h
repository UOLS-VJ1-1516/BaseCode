#pragma once

class Level
{
private:
	friend class LevelParser;
	Level();
	std::vector<Tileset> tilesets;
	std::vector<Layer *> layers;
public:
	void update();
	void render();

	std::vector<Tileset> * getTilesets()
	{
		return & this->tilesets;
	}

	std::vector<Layer *> * getLayers()
	{
		return &this->layers;
	}
};