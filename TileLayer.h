#pragma once
#include <iostream>
#include "Tileset.h"
#include "Vector2D.h"
#include <vector>

class TileLayer
{
private:
	int tileWidth;
	int tileHeight;
	Vector2D position;
	const std::vector<Tileset> &tilesets;
	std::vector<std::vector<int>> tileIDs;
public:
	TileLayer(int, int, const std::vector<Tileset>&);
	virtual ~TileLayer();
	void Update();
	void Render();
	void SetTileIDs(const std::vector<std::vector<int>>&);
	const Tileset * GetTileset(int);
};